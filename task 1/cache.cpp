#include "cache.h"
#include <unordered_map>
#include <vector>

inline int up(const int i) {
    return (i - 1) / 2;
};
    cache_st::cache_st(int sz) : sz_max(sz) {};

    bool cache_st::check_hit(int val) {
        if (hash_.find(val) == hash_.end()) {
            insert_in_top(val);
            hash_.insert({val, &cache[0]});
            return false;
        }
        else {
            hash_.find(val)->second->freq++;
            int i = hash_.find(val)->second - &cache[0];
            while((i != 0) || (cache[i].freq < cache[up(i)].freq)) {
                block vir = {0, 0};
                vir = cache[i];
                cache[i] = cache[up(i)];
                cache[up(i)] = vir;
                hash_.find(cache[i].val)->second = &cache[i];
                i = up(i);
            }
            return true;
        };
    };

inline void cache_st::insert_in_top(int val) {
        int real_size = cache.size();
        int i = real_size;
        block vir = {0, 0};
        if (sz_max > real_size) {
            cache.push_back({val, 0});
            while(cache[0].val != val) {
                vir = cache[i];
                cache[i] = cache[up(i)];
                cache[up(i)] = vir;
                hash_.find(cache[i].val)->second = &cache[i];
                i = up(i);
            };
            return;
        }
        else {
            hash_.erase(cache[0].val);
            cache[0] = {val, 0};
            return;
        }
};