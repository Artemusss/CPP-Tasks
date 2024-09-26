#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

template <typename T> class LFU {
    struct freq_node;
    
    struct node {
        T val;
        typename std::list<freq_node>::iterator head;

        public:
        node(T inp, typename std::list<freq_node>::iterator adr) : val(inp), head(adr) {};
    };
    

    struct freq_node{
        int freq;
        typename std::list<node>::iterator list_node;

        public:
        freq_node(int inp, typename std::list<node>::iterator adr) : freq(inp), list_node(adr) {};
    };

    
    private:
    int sz_max;
    std::unordered_map<T, typename std::list<node>::iterator> hash;
    std::list<freq_node> list_freq;

    public:
    LFU(int size) : sz_max(size) {};

    bool check_hit(T val) {
        if (hash.find(val) == hash.end()) {
            if(hash.size() == 0) {
                list_freq.push_front(freq_node(0, new std::list<node>));
                list_freq.front().list_node->push_back(node(val, &list_freq.front()));
                hash.insert(val, &list_freq.front().list_node->back());
            }
            else if(hash.size() < sz_max) {
                if (list_freq.front().freq != 0) {
                    list_freq.push_front(freq_node(0, new std::list<node>));
                }
                list_freq.front().list_node->push_back(node(val, &list_freq.front()));
                hash.insert(val, &list_freq.front().list_node->back());
            }
            else {
                T del_val = list_freq.front().list_node->front().val;
                hash.erase(del_val);
                list_freq.front().list_node->erase(0);
                if ((list_freq.front().freq != 0) && (list_freq.front().list_node->size() == 0))
                    list_freq.erase(0);
                if (list_freq.front().freq != 0)
                    list_freq.push_front(freq_node(0, new std::list<node>));
                list_freq.front().list_node->push_back(node(val, &list_freq.front()));
                hash.insert(val, &list_freq[0].list_node->back());
            }
            return false;
        }
        else {
            auto adr = hash.find(val).second;
            if (adr->head == &list_freq.back()) {
                list_freq.push_back(freq_node(adr->head->freq + 1, new std::list<node>));
                list_freq.back().list_node->push_back(node(val, ++(adr->head)));
                std::advance(list_freq.end(), -2)->node_list->erase(adr);
                if (std::advance(list_freq.end(), -2)->node_list->size() == 0)
                    list_freq.erase(std::advance(list_freq.end(), -2));
                hash.find(val).second = &list_freq.back().list_node->back();
            }
            else if (adr->head->freq + 1 == ++(adr->head)->freq) {
                ++(adr->head)->list_node->push_back(node(val, ++(adr->head)));
                adr->head->list_node->erase(adr);
                if (adr->head->list_node->size() == 0)
                    list_freq.erase(adr->head);
                hash.find(val).second = &(++(adr->head)->list_node->back());
            }
            else {
                list_freq.insert(++(adr->head), freq_node(adr->head->freq + 1, new std::list<node>));
                ++(adr->head)->list_node->push_back(node(val, ++(adr->head)));
                adr->head->list_node->erase(adr);
                if (adr->head->list_node->size() == 0)
                    list_freq.erase(adr->head);
                hash.find(val).second = &(++(adr->head)->list_node->back());    
            }
            return true;
        }
    };
};