#ifndef INCLUDE_CACHE_HPP
#define INCLUDE_CACHE_HPP

#include <unordered_map>
#include <cassert>
#include <list>
#include <iterator>
#include <cstddef>

template <typename T> class LFU { // two template parameters: one for keys, one for pages
    struct freq_node;
    
    using freq_iterator = typename std::list<freq_node>::iterator;
    struct node {
        T val;
        freq_iterator head;
    };
    
    struct freq_node {
        std::list<node> list_node;
        std::size_t freq;
        freq_node(std::size_t freq_) : freq(freq_) {}
    };

    std::size_t sz_max_; 
    std::unordered_map<T, typename std::list<node>::iterator> hash_;
    std::list<freq_node> list_freq_;

    public:
    explicit LFU(std::size_t size) : sz_max_(size) {}

    void hash_dump() const {
        std::cout << '\n';
        for(auto i = hash_.begin(); i != hash_.end(); i = std::next(i))
            std::cout << "Val in hash: " << i->first << '\n';
        std::cout << '\n';
    }

    void cache_dump() const {
        std::cout << '\n';
        for(auto i = list_freq_.begin(); i != list_freq_.end(); ++i) {
            std::cout << "Freq: " << i->freq << '\n';
            for(auto q = i->list_node.begin(); q != i->list_node.end(); ++q)
                std::cout << "Val in cache: " << q->val << '\n';
        }
        std::cout << '\n';
    }

    bool check_hit(const T &val) {
        auto hash_it = hash_.find(val);
        if (hash_it == hash_.end()) {
            if(hash_.empty()) {
                list_freq_.emplace_front(0);
            } else if (hash_.size() < sz_max_) {
                if (list_freq_.front().freq != 0) {
                    list_freq_.emplace_front(0);
                }
            } else {
                freq_node &first_freq_node = list_freq_.front();
                std::list<node> &list_node_first = first_freq_node.list_node;
                T &del_val = list_node_first.front().val;

                hash_.erase(del_val);
                list_node_first.erase(list_node_first.begin());
                if ((first_freq_node.freq != 0) && (list_node_first.empty())) {
                    list_freq_.erase(list_freq_.begin());
                    list_freq_.emplace_front(0);
                } else if (first_freq_node.freq != 0)
                    list_freq_.emplace_front(0);
            }

            list_freq_.front().list_node.emplace_back(val, list_freq_.begin());
            hash_.insert({val, std::prev(list_freq_.front().list_node.end())});
            return false;
        } else {
            auto page_it = hash_it->second;
            freq_iterator head_it = page_it->head;

            if (auto max_freq_it = std::prev(list_freq_.end()); head_it == max_freq_it) {
                auto &max_freq_node = list_freq_.emplace_back(max_freq_it->freq + 1);
                max_freq_node.list_node.emplace_back(val, std::next(max_freq_it));
            }
            else {
                auto next_head_it = std::next(head_it);
                if ((head_it->freq + 1) == (next_head_it->freq)) {
                    next_head_it->list_node.emplace_back(val, next_head_it);
                } else {
                    list_freq_.emplace(next_head_it, head_it->freq + 1);
                    auto new_next_head_it = std::next(head_it);
                    new_next_head_it->list_node.emplace_back(val, new_next_head_it);    
                }
            }

            hash_.find(val)->second = std::prev(std::next(head_it)->list_node.end());
            if (head_it->list_node.size() == 1)
                list_freq_.erase(head_it);
            else
                head_it->list_node.erase(page_it);
            return true;
        }
    }
};

#endif // INCLUDE_CACHE_HPP
