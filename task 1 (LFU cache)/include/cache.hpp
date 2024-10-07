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

    std::size_t sz_max; 
    std::unordered_map<T, typename std::list<node>::iterator> hash;
    std::list<freq_node> list_freq;

    public:
    LFU(std::size_t size) : sz_max(size) {}

    void hash_dump(){
        std::cout << '\n';
        for(auto i = hash.begin(); i != hash.end(); i = std::next(i))
            std::cout << "Val in hash: " << i->first << '\n';
        std::cout << '\n';
    }

    
    void cache_dump() {
        std::cout << '\n';
        for(auto i = list_freq.begin(); i != list_freq.end(); i = std::next(i)) {
            std::cout << "Freq: " << i->freq << '\n';
            for(auto q = i->list_node.begin(); q != i->list_node.end(); q = std::next(q))
                std::cout << "Val in cache: " << q->val << '\n';
        }
        std::cout << '\n';
    }

    bool check_hit(const T &val) {
        auto hash_it = hash.find(val);
        if (hash_it == hash.end()) {
            if(hash.empty()) {
                list_freq.emplace_front(0);
            } else if (hash.size() < sz_max) {
                if (list_freq.front().freq != 0) {
                    list_freq.emplace_front(0);
                }
            } else {
                freq_node &first_freq_node = list_freq.front();
                std::list<node> &list_node_first = first_freq_node.list_node;
                T &del_val = list_node_first.front().val;

                std::cout << "LOL KEK\n";
                hash.erase(del_val);
                list_node_first.erase(list_node_first.begin());
                std::cout << "POBEDA\n";
                if ((first_freq_node.freq != 0) && (list_node_first.empty())) {
                    list_freq.erase(list_freq.begin());
                    list_freq.emplace_front(0);
                } else if (first_freq_node.freq != 0)
                    list_freq.emplace_front(0);
            }

            std::cout << "HERE\n";
            list_freq.front().list_node.emplace_back(val, list_freq.begin());
            hash.insert({val, std::prev(list_freq.front().list_node.end())});

            hash_dump();
            cache_dump();
            return false;
        } else {
            auto page_it = hash_it->second;
            freq_iterator head_it = page_it->head;

            if (auto max_freq_it = std::prev(list_freq.end()); head_it == max_freq_it) {
                auto &max_freq_node = list_freq.emplace_back(max_freq_it->freq + 1);
                max_freq_node.list_node.emplace_back(val, std::next(max_freq_it));
            }
            else {
                auto next_head_it = std::next(head_it);
                if ((head_it->freq + 1) == (next_head_it->freq)) {
                    next_head_it->list_node.emplace_back(val, next_head_it);
                } else {
                    list_freq.emplace(next_head_it, head_it->freq + 1);
                    auto new_next_head_it = std::next(head_it);
                    new_next_head_it->list_node.emplace_back(val, new_next_head_it);    
                }
            }

            hash.find(val)->second = std::prev(std::next(head_it)->list_node.end());
            if (head_it->list_node.size() == 1)
                list_freq.erase(head_it);
            else
                head_it->list_node.erase(page_it);
            assert(hash.find(val)->first == val);
            return true;
        }
    }
};

#endif // INCLUDE_CACHE_HPP
