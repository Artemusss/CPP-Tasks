#include <iostream>
#include <unordered_map>
#include <vector>

struct block {
    int val;
    int freq;
 };

inline int up(const int i) {
    return (i - 1) / 2;
}

struct cache_st {
    int sz_max;
    std::vector <block> cache;
    std::unordered_map <int, block*> hash_;

    cache_st(int sz) : sz_max(sz) {};

    bool check_hit(int val, std::vector <block> & cache, std::unordered_map <int, block*> & hash_) {
        //std::cout << "POBEDA111111\n" << val <<"\n";
        if (hash_.find(val) == hash_.end()) {
            //std::cout << "POBEDA222222\n";
            insert_in_top(val, cache, hash_);
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

inline void insert_in_top(int val, std::vector <block> & cache, std::unordered_map <int, block*> & hash_) {
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

int main() {
    int size = 0, val = 0, cou = 0, num = 0;

    std::cout << "Please, write size of LFU cache\n";
    std::cin >> size;
    cache_st c{size};

    std::cout << "Write number of values in data\n";
    std::cin >> num;
    std::cout << "Write data of int values\n";

    for(int i = 0; i < num; i++) {
        std::cin >> val;
        if (c.check_hit(val, c.cache, c.hash_))
            cou++;
    }
    std::cout << "Hits: " << cou << "\n";
}