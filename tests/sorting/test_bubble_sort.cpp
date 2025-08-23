#include <iostream>

#include "sorting/bubble_sort.hpp"
#include <vector>
#include <algorithm>
#include <cassert>

void test_bubble_sort() {
    std::vector<int> vec = {5, 2, 9, 1, 5, 6};
    algorithms::sorting::bubble_sort(vec.begin(), vec.end());
    assert(std::is_sorted(vec.begin(), vec.end()));

    std::cout << "Bubble sort test passed!" << std::endl;

    // Custom comparator test
    std::vector<int> vec2 = {5, 2, 9, 1, 5, 6};
    algorithms::sorting::bubble_sort(vec2.begin(), vec2.end(), std::greater<>());
    assert(std::is_sorted(vec2.begin(), vec2.end(), std::greater<>()));
    std::cout << "Bubble sort custom comparator test passed!" << std::endl;
}

int main() {
    test_bubble_sort();
    std::cout << "All tests passed." << std::endl;
    return 0;
}