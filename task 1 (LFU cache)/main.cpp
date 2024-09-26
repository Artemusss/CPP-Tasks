#include <iostream>
#include <assert.h>
#include "cache.hpp"

int main() {
    int size = 0, val = 0, cou = 0, num = 0;

    std::cin >> size;
    assert(size > 0);
    LFU<int> c{size};

    std::cin >> num;
    assert(num > 0);

    for(int i = 0; i < num; i++) {
        std::cin >> val;
        std::cout << "Number of value inp: " << i << "  Value: " << val << "\n";
        if (c.check_hit(val))
            cou++;
    }
    assert(cou >= 0);
    std::cout << "Hits: " << cou << "\n";
}