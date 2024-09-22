#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <assert.h>
#include "../best_cache/best_cache.cpp"
#include "../include/cache.hpp"
using namespace std;

int main() {
    int nm = 0;
    string name_test = "", name_ans = "";
    cout << "Write number of test (in range 1-3)" << "\n";
    cin >> nm;
    std::ifstream inp, ans_file;
    switch (nm)
    {
    case 1:
        inp.open("../1.txt", ios_base::in);
        ans_file.open("../1_ans.txt", ios_base::in);
        break;
    case 2:
        inp.open("../2.txt", ios_base::in);
        ans_file.open("../2_ans.txt", ios_base::in);
        break;
    case 3:
        inp.open("../3.txt", ios_base::in);
        ans_file.open("../3_ans.txt", ios_base::in);
        break;
    
    default:
        cout << "Wrong number of test" << "\n";
        break;
    }
    cout << inp.is_open() << " " << ans_file.is_open() << "\n";
    int sz = 0, num = 0, hits_best = 0, hits_lfu = 0, val = 0, ans = -1;;
    std::vector <int> data_val, cache;
    inp >> sz >> num;
    cache_st c{sz};
    for(int i = 0; i < num; i++) {
        inp >> val;
        cout <<"Number of i: " << i << "\n";
        cout << val << "\n";
        if (c.check_hit(val)) {
            cout << "HERE1" << "\n";
            hits_lfu++;
        }
        data_val.push_back(val);
    }
    hits_best = chech_hits_best_cache(data_val, num, cache, sz);

    ans_file >> ans;
    if (ans == hits_lfu)
        cout << "Test " << nm << " pass" << "\n";
    else
        cout << "Error\n";
    
    cout << "Cache LFU hits: " << hits_lfu << "\n" << "Best cache hits: " << hits_best << "\n"; 

    inp.close();
    ans_file.close();
}