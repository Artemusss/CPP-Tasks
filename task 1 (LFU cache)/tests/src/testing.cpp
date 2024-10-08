#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <assert.h>
#include "../ideal_cache/src/ideal_cache.cpp"
#include "../include/cache.hpp"

int main() {
    int nm = 0;
    std::cout << "Write number of test (in range 1-3)" << "\n";
    std::cin >> nm;
    std::ifstream inp, ans_file;
    switch (nm)
    {
    case 1:
        inp.open("../1.txt", std::ios_base::in);
        ans_file.open("../1_ans.txt", std::ios_base::in);
        break;
    case 2:
        inp.open("../2.txt", std::ios_base::in);
        ans_file.open("../2_ans.txt", std::ios_base::in);
        break;
    case 3:
        inp.open("../3.txt", std::ios_base::in);
        ans_file.open("../3_ans.txt", std::ios_base::in);
        break;
    
    default:
        std::cout << "Wrong number of test" << "\n";
        break;
    }
    std::cout << inp.is_open() << " " << ans_file.is_open() << "\n";
    int sz = 0, num = 0, hits_best = 0, hits_lfu = 0, val = 0, ans = -1;;
    std::vector<int> data_val, cache;
    inp >> sz >> num;
    LFU<int> c{sz};
    for(int i = 0; i < num; i++) {
        inp >> val;
        std::cout << val << "\n";
        hits_lfu += c.check_hit(val);
        data_val.push_back(val);
    }
    hits_best = check_hits_best_cache(data_val, num, cache, sz);

    ans_file >> ans;
    if (ans == hits_lfu)
        std::cout << "Test " << nm << " pass" << '\n';
    else
        std::cout << "Error\n";
    
    std::cout << "Cache LFU hits: " << hits_lfu << '\n' << "Best cache hits: " << hits_best << '\n'; 

    inp.close();
    ans_file.close();
}