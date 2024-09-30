#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

template <typename T> class LFU {
    struct freq_node;
    
    using freq_iterator = typename std::list<freq_node>::iterator;
    struct node {
        T val;
        freq_iterator head;
    };
    
    struct freq_node{
        int freq;
        typename std::list<node> list_node;
    };

    
    private:
    int sz_max;
    std::unordered_map<T, typename std::list<node>::iterator> hash;
    std::list<freq_node> list_freq;

    public:
    LFU(int size) : sz_max(size) {}

    bool check_hit(T val) {
        if (hash.find(val) == hash.end()) {
            if(hash.empty()) { 
                list_freq.emplace_front(0, list_freq.begin());
                list_freq.front().list_node.emplace_back(val, list_freq.begin());
                hash.insert(val, std::prev(list_freq.front().list_node.end()));
            }
            else if(hash.size() < sz_max) {
                if (list_freq.front().freq != 0) {
                    list_freq.emplace_front(0, list_freq.begin());
                }
                list_freq.front().list_node.emplace_back(val, list_freq.begin());
                hash.insert(val, std::prev(list_freq.front().list_node.end()));
            }
            else {
                T del_val = list_freq.front().list_node.front().val;
                hash.erase(del_val);
                list_freq.front().list_node.erase(0);
                if ((list_freq.front().freq != 0) && (list_freq.front().list_node.size() == 0))
                    list_freq.erase(0);
                if (list_freq.front().freq != 0)
                    list_freq.emplace_front(0, list_freq.begin());
                list_freq.front().list_node.emplace_back(val, list_freq.begin());
                hash.insert(val, std::prev(list_freq.front().list_node.end()));
            }
            return false;
        }
        else {
            auto adr = hash.find(val)->second;
            if (adr->head == std::prev(list_freq.end())) {
                list_freq.emplace_back(adr->head->freq + 1, std::prev(list_freq.end()));
                list_freq.back().list_node.emplace_back(val, std::next(adr->head));
                auto penult = list_freq.end();
                std::advance(penult, -2);
                penult->list_node.erase(adr);
                if (penult->list_node.size() == 0)
                    list_freq.erase(penult);
                hash.find(val)->second = std::prev(list_freq.back().list_node.end());
            }
            else if (adr->head->freq + 1 == std::next(adr->head)->freq) {
                std::next(adr->head)->list_node.emplace_back(val, std::next(adr->head));
                adr->head->list_node.erase(adr);
                if (adr->head->list_node.size() == 0)
                    list_freq.erase(adr->head);
                hash.find(val)->second = std::prev(std::next(adr->head)->list_node.end());
            }
            else {
                list_freq.insert(std::next(adr->head), adr->head->freq + 1, std::next(adr->head));
                std::next(adr->head)->list_node.emplace_back(val, std::next(adr->head));
                adr->head->list_node.erase(adr);
                if (adr->head->list_node.size() == 0)
                    list_freq.erase(adr->head);
                hash.find(val)->second = std::prev(std::next(adr->head)->list_node.end());    
            }
            return true;
        }
    }
};