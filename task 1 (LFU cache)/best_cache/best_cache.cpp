#include<iostream>
#include<vector>
#include<algorithm>
#include<assert.h>

// TODO: сделать отдельно лучший кеш

int chech_hits_best_cache(std::vector<int> inp, int size_inp, std::vector<int> cache, int sz) {
    int cou = 0;
    for(int i = 0; i < size_inp; i++) {
        if (std::find(cache.begin(), cache.end(), inp[i]) == cache.end()) {
                int del = 0, pos = 0, max = 0;
                if (cache.size() < sz)
                    cache.push_back(inp[i]);
                else {
                    max = std::find(inp.begin(), inp.end(), cache[0]) - cache.begin();
                    del = 0;
                    for(int q = 0; q < cache.size()-1; q++) {
                       pos = std::find(inp.begin(), inp.end(), cache[q + 1]) - cache.begin();
                       assert(pos >= 0);
                       assert(pos <= cache.end() - cache.begin());
                       if (max < pos)
                        max = pos;
                        del = q + 1;
                    }
                    assert(del >= 0);
                    assert(del < cache.size());
                    cache.erase(cache.begin() + del);
                    cache.push_back(inp[i]);
                };
        }
        else {
            cou++;
        }
    }
    return cou;

}

