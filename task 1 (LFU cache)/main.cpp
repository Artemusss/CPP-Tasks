#include <iostream>
#include "cache.hpp"

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
        if (c.check_hit(val))
            cou++;
    }
    std::cout << "Hits: " << cou << "\n";
}