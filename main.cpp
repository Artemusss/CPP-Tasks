#include <iostream>
#include <unordered_map>
#include <vector>

struct block {
    int val;
    int freq;
 };

 inline int right(const int i) {
    return 2 * i + 1;
}

inline int left(const int i) {
    return 2 * (i + 1);
}

inline int up(const int i) {
    return (i - 1) / 2;
}

struct cache_st {
    int sz_max;
    std::vector<block> cache;
    std::unordered_map <int, block*> hash_;

    cache_st(int sz) : sz_max(sz) {};

    bool check_hit(int val) {
        std::cout << "POBEDA111111\n" << val <<"\n";
        if (hash_.find(val) == hash_.end()) {
            std::cout << "POBEDA222222\n";
            hash_.insert({val, insert_in_top(val)});
            return false;
        }
        else {
            hash_.find(val)->second->freq++;
            std::cout << "POBEDA7777777\n" << &cache[0] << "\n";
            int i = ((hash_.find(val))->second - &cache[0]);
            std::cout << "POBEDA88888\n" << i << "\n";
            while((i != 0) || (cache[i].freq < cache[up(i)].freq)) {
                block vir = {0, 0};
                vir = cache[i];
                cache[i] = cache[up(i)];
                cache[up(i)] = vir;
                i = up(i);
            }
            std::cout << "POBEDA333333\n";
            return true;
        };
    };

inline block* insert_in_top(int val) {
        int real_size = cache.size();
        int i = real_size;
        block vir = {0, 0};
        if (sz_max > real_size) {
            std::cout << "POBEDA444444\n";
            cache.push_back({val, 0});
            while(cache[0].val != val) {
                vir = cache[i];
                cache[i] = cache[up(i)];
                cache[up(i)] = vir;
            };
            std::cout << "POBEDA555555\n";
            return &cache[0];
        }
        else {
            std::cout << "POBEDA666666\n";
            hash_.erase(cache[0].val);
            cache[0] = {val, 0};
            return &cache[0];
        }
};

};

int main() {
    int size = 0, val = 0, cou = 0;

    std::cout << "Please, write size of LFU cache\n";
    std::cin >> size;
    cache_st c{size};
    std::cout << "Write data of int values\n";

    while(true) {
        std::cin >> val;
        if (c.check_hit(val))
            cou++;
    }
    std::cout << "Hits: " << cou << "\n";
}