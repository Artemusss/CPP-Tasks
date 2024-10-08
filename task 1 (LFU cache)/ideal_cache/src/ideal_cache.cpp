#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

int check_hits_ideal_cache(std::vector<int> &inp, int size_inp, std::vector<int> &cache, int sz) {
    int cou = 0;
    for(int i = 0; i < size_inp; i++) {
        if (std::find(cache.begin(), cache.end(), inp[i]) == cache.end()) {
                if (cache.size() < sz)
                    cache.push_back(inp[i]);
                else {
                    auto position_in_input_it = inp.begin();
                    std::advance(position_in_input_it, i + 1);

                    auto max = std::find(position_in_input_it, inp.end(), cache[0]), del = cache.begin();
                    std::vector<int>::iterator pos;
                    if (max != inp.end()) {
                        for(auto cache_elem_it = std::next(cache.begin()); cache_elem_it != cache.end(); ++cache_elem_it) {
                            pos = std::find(position_in_input_it, inp.end(), *cache_elem_it);
                            if (max < pos) {
                                max = pos;
                                del = cache_elem_it;
                            }
                           if (max == inp.end())
                                break;
                        }
                    }
                    if (std::find(position_in_input_it, inp.end(), inp[i]) < max) {
                        cache.erase(del);
                        cache.push_back(inp[i]);
                    }
                };
        }
        else {
            cou++;
        }
    }
    return cou;

}

