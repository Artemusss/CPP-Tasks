#include <iostream>
#include <cstddef>

#include "cache.hpp"

int get_page(const int& key) {return key;};

int main() {

    std::size_t size;
    std::cin >> size;
    if (std::cin.bad()) {
        std::cerr << "Incorrect input size cache\n";
        return 1;
    }

    LFU<int, int> c{size, get_page};

    int num;
    std::cin >> num;
    if (std::cin.bad()) {
        std::cerr << "Incorrect input number of elements\n";
        return 1;
    }

    int val, counter = 0;
    for(int i = 0; i < num; i++) {
        std::cin >> val;
        //std::cout << "Number of value inp: " << i << "  Value: " << val << '\n';
        counter += c.check_hit(val);
        //std::cout << "Hits now: " << counter << '\n';
    }
    std::cout << "Hits: " << counter << '\n';
}
