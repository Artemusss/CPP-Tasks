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
            std::cout << "52" << "\n";
            int i = insert_in_top(val);
            hash_.find(val)->second = &cache[i];
            assert(hash_.find(val)->second->val == val);
            assert(hash_.find(val)->second - &cache[0] >= 0);
            assert(hash_.find(val) != hash_.end());
            return false;
        }
        else {
            std::cout << "HERE  " << cache[0].val << "\n";
            assert(hash_.find(val)->second->val == val);
            std::cout << hash_.find(val)->second - &cache[0] << "\n";
            std::cout << hash_.find(val)->second->val << "\n";
            hash_.find(val)->second->freq++;
            assert(hash_.find(val)->second->val == val);
            int i = hash_.find(val)->second - &cache[0];
            std::cout << i << "\n";
            assert(i >= 0);
            assert(i < sz_max);
            while(left(i) < sz_max) {
                block vir = {0, 0};
                vir = cache[i];
                if (cache[i].freq >= cache[left(i)].freq) {
                    cache[i] = cache[left(i)];
                    cache[left(i)] = vir;
                    hash_.find(cache[i].val)->second = &cache[i];
                    assert(hash_.find(cache[i].val) != hash_.end());
                    assert(i < sz_max);
                    i = left(i);
                }
                else if (right(i) < sz_max){
                    if (cache[i].freq >= cache[left(i)].freq){
                        cache[i] = cache[right(i)];
                        cache[right(i)] = vir;
                        hash_.find(cache[i].val)->second = &cache[i];
                        assert(i < sz_max);
                        assert(hash_.find(cache[i].val) != hash_.end());
                        i = right(i);
                    }
                    else
                        break;
                }
                else
                    break;
            }
            hash_.find(cache[i].val)->second = &cache[i];
            return true;
        };
    };

inline int cache_st::insert_in_top(const int val) {
        int real_size = cache.size();
        assert(real_size >= 0);
        int i = real_size;
        std::cout << i << "\n";
        block vir = {0, 0};
        if (sz_max > real_size) {
            cache.push_back({val, 0});
            while(i > 0) {
                if (cache[up(i)].freq != 0) {
                    vir = cache[i];
                    cache[i] = cache[up(i)];
                    cache[up(i)] = vir;
                    hash_.find(cache[i].val)->second = &cache[i];
                    assert(hash_.find(cache[i].val) != hash_.end());
                    assert(i > 0);
                    std::cout << "1 " << cache[i].val << " " << cache[i].freq << "\n";
                    std::cout << "2 " << cache[up(i)].val << " " << cache[up(i)].freq << "\n";
                    i = up(i);
                }
                else 
                    break;
            };
            std::cout << i << "\n";
            hash_.insert({val, &cache[i]});
            hash_.find(val)->second = &cache[i];
            return i;
        }
        else {
            hash_.erase(cache[0].val);
            assert(hash_.find(cache[0].val) == hash_.end());
            int q = 0;
            while(left(q) < sz_max) {
                if (cache[left(q)].freq == 0) {
                    block vir = {0, 0};
                    vir = cache[left(q)];
                    cache[left(q)] = cache[q];
                    cache[q] = vir;
                    hash_.find(cache[q].val)->second = &cache[q];
                    q = left(q);
                }
                else if (right(q) < sz_max) {
                    if ((cache[right(q)].freq == 0)){
                        block vir = {0, 0};
                        vir = cache[right(q)];
                        cache[right(q)] = cache[q];
                        cache[q] = vir;
                        hash_.find(cache[q].val)->second = &cache[q];
                        q = right(q);
                    }
                    else
                        break;
                }
                else
                    break;

            }
            hash_.insert({val, &cache[q]});
            return q;
        }
};
