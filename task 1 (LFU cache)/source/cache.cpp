#include "cache.hpp"
#include <unordered_map>
#include <vector>
#include <iostream>
#include <assert.h>

inline int up(const int i) {
    return (i - 1) / 2;
}
inline int left(const int i) {
	return 2 * i + 1;
}
inline int right(const int i) {
	return 2 * i + 2;
}
    cache_st::cache_st(const int sz) : sz_max(sz) {};

    bool cache_st::check_hit(const int val) {
        if (hash_.find(val) == hash_.end()) {
            insert_in_top(val);
            hash_.insert({val, &cache[0]});
            return false;
        }
        else {
            hash_.find(val)->second->freq++;
            int i = hash_.find(val)->second - &cache[0];
            while(((right(i) <= sz_max) || (left(i) <= sz_max)) && ((cache[i].freq > cache[left(i)].freq) || (cache[i].freq > cache[right(i)].freq))) {
                block vir = {0, 0};
                vir = cache[i];
                if (cache[i].freq > cache[left(i)].freq){
                    cache[i] = cache[left(i)];
                    cache[left(i)] = vir;
                    hash_.find(cache[i].val)->second = &cache[i];
                    hash_.find(cache[left(i)].val)->second = &cache[left(i)];
                    i = left(i);
                }
                else{
                    cache[i] = cache[right(i)];
                    cache[right(i)] = vir;
                    hash_.find(cache[i].val)->second = &cache[i];
                    hash_.find(cache[right(i)].val)->second = &cache[right(i)];
                    i = right(i);

                }
            }
            return true;
        };
    };

inline void cache_st::insert_in_top(const int val) {
        int real_size = cache.size();
        int i = real_size;
        block vir = {0, 0};
        if (sz_max > real_size) {
            cache.push_back({val, 0});
            while(cache[0].val != val) {
                std::cout << "POBEDA111";
                vir = cache[i];
                cache[i] = cache[up(i)];
                cache[up(i)] = vir;
                hash_.find(cache[i].val)->second = &cache[i];
                hash_.find(cache[up(i)].val)->second = &cache[up(i)];
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



/* The dumbest debug ever been

struct cache_st {
    int sz_max;
    std::vector <block> cache;
    std::unordered_map <int, block*> hash_;

    cache_st(int sz) : sz_max(sz) {};

    bool check_hit(int val) {
        //std::cout << "POBEDA111111\n" << val <<"\n";
        if (hash_.find(val) == hash_.end()) {
            //std::cout << "POBEDA222222\n";
            insert_in_top(val);
            hash_.insert({val, &cache[0]});
            //std::cout << hash_.find(val)->second->val << "\n" << hash_.find(val)->second->freq << "\n";
            //std::cout << hash_.find(1)->second->val << "\n" << hash_.find(1)->second->freq << "\n";
            return false;
        }
        else {
            //std::cout << hash_.size() << "\n";
            hash_.find(val)->second->freq++;
            //std::cout << "POBEDA7777777\n" << cache[1].freq << "\n" << cache[1].val << "\n" << hash_.find(val)->second->freq << "\n";
            int i = hash_.find(val)->second - &cache[0];
            //std::cout << "POBEDA88888\n" << i << "\n";
            while((i != 0) || (cache[i].freq < cache[up(i)].freq)) {
                block vir = {0, 0};
                vir = cache[i];
                cache[i] = cache[up(i)];
                cache[up(i)] = vir;
                hash_.find(cache[i].val)->second = &cache[i];
                i = up(i);
            }
            //std::cout << "POBEDA333333\n";
            return true;
        };
    };

inline void insert_in_top(int val) {
        int real_size = cache.size();
        int i = real_size;
        block vir = {0, 0};
        if (sz_max > real_size) {
           // std::cout << "POBEDA444444\n";
            cache.push_back({val, 0});
            while(cache[0].val != val) {
                vir = cache[i];
                cache[i] = cache[up(i)];
                cache[up(i)] = vir;
                hash_.find(cache[i].val)->second = &cache[i];
                i = up(i);
            };
            //std::cout << "POBEDA555555\n" << cache[0].val << "\n" << cache[0].freq << "\n";
            return;
        }
        else {
            //std::cout << "POBEDA666666\n" << cache[0].val << "\n" << cache[0].freq << "\n";
            hash_.erase(cache[0].val);
            cache[0] = {val, 0};
            return;
        }
};

};
*/
