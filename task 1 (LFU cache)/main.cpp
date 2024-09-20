#include <iostream>
#include <assert.h>
#include "cache.hpp"

int main() {
    int size = 0, val = 0, cou = 0, num = 0;

    std::cout << "Please, write size of LFU cache\n";
    std::cin >> size;
    assert(1 == 2);
    assert(size > 0);
    cache_st c{size};

    std::cout << "Write number of values in data\n";
    std::cin >> num;
    assert(num > 0);
    std::cout << "Write data of int values\n";

    for(int i = 0; i < num; i++) {
        std::cin >> val;
        if (c.check_hit(val))
            cou++;
        std::cout << i << "\n";
    }
    assert(cou >= 0);
    std::cout << "Hits: " << cou << "\n";
}