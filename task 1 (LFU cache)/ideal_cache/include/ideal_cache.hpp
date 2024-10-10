#include <list>
#include <unordered_map>
#include <iterator>
#include <cstddef>
#include <functional>

template <typename page_T, typename key_T> class ideal_cache_with_input {

    struct input_st {
        std::list<key_T> data;
        std::unordered_map<key_T, std::list<int>> hash_tb;
        std::size_t size;
    }

    struct node {
        key_T key;
        page_T page;
    }

    input_st input_;

    using get_page_T = typename std::function<page_T (const key_T&)>;

    std::list<node> cache_;
    std::unordered_map<key_T, std::list<node>::iterator> hash_tb_;
    std::size_t max_size_;
    get_page_T get_page_;

    explicit ideal_cache_with_input (std::size_t sz_cache, get_page_T function, std::size_t sz_inp) : max_size_(sz_cache),
                                                                                                      get_page_(function),
                                                                                                      input_.size(sz_inp) {} 

    void filling_input(key_T key, int pos) {
        input_.data.emplace_back(key);

        auto hash = input.hash_tb;
        auto hash_node_it = hash.find(key);

        if(hash_node_it == hash.end()) {
            hash.emplace(key);
            hash.find(key)->second.emplace_back(pos);
        }
        else {
            hash_node_it->second.emplace_back(pos);
        }

    }

    int check_hits_ideal_cache() {
        for(int i = 0; i < input_.size; i++) {
            
            key_T val = input_.data.front;
            input_.data.erase(input_data.begin());

            auto del_it = input_.hash_tb.find(val);
            auto del_lst = del_it->second;
            if (del_lst.size() == 1) {
                input_.hash_tb.erase(del_it)
            }
            else
                del_lst.erase(del_lst.begin());

            auto key_it = hash_tb_.find(val);
            if (key_it == hash_tb_.end()) {
                if (cache_.size() < max_size_) {

                    cache_.emplace_back({key, get_page_(key)});
                    hash_tb_.emplace(key, std::prev(cache_.end()));

                }
                else {

                    auto val_in_inp_it = input_.hash_tb.find(val);
                    int max_pos = 0;

                    if (val_in_inp_it != input_.hash_tb.end()) {

                        for(auto j = cache_.begin(); j != cache_.end(); ++j) {

                        }
                    }
                }
            }
        }
    }

}