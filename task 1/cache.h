#include <unordered_map>
#include <vector>

struct block {
    int val;
    int freq;
};

struct cache_st{
    int sz_max;
    std::vector <block> cache;
    std::unordered_map <int, block*> hash_;

    cache_st(int sz);
    bool check_hit(int val);
    inline void insert_in_top(int val);
};