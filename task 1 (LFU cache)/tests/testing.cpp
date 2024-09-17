#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "../best_cache/best_cache.cpp"
#include "../include/cache.hpp"
using namespace std;

int main() {
    char nm = 0;
    cout << "Write number of test (in range 1-3)" << "\n";
    cin >> nm;
    ifstream inp(string(nm + ".txt")), ans_file(string(nm + "_ans.txt"));
    int sz = 0, num = 0, hits_best = 0, hits_lfu = 0, val = 0, ans = -1;;
    std::vector <int> data_val, cache;
    inp >> sz >> num;
    cache_st c{sz};
    for(int i = 0; i < num; i++) {
        inp >> val;
        if (c.check_hit(val))
            hits_lfu++;
        data_val.push_back(val);
    }
    hits_best = chech_hits_best_cache(data_val, num, cache, sz);

    ans_file >> ans;
    if (ans == hits_lfu)
        cout << "Test " << nm << " pass" << "\n";
    else
        cout << "Error\n";
    
    cout << "Cache LFU hits: " << hits_lfu << "\n" << "Best cache hits: " << hits_best << "\n"; 

}