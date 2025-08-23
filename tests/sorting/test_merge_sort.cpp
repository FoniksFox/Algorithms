#include <iostream>

#include "sorting/merge_sort.hpp"
#include <vector>
#include <algorithm>
#include <cassert>

void test_merge_sort() {
    std::vector<int> vec = {5, 2, 9, 1, 5, 6};
    algorithms::sorting::merge_sort(vec.begin(), vec.end());
    assert(std::is_sorted(vec.begin(), vec.end()));

    std::cout << "Merge sort test passed!" << std::endl;

    // Custom comparator test
    std::vector<int> vec2 = {5, 2, 9, 1, 5, 6};
    algorithms::sorting::merge_sort(vec2.begin(), vec2.end(), std::greater<>());
    assert(std::is_sorted(vec2.begin(), vec2.end(), std::greater<>()));
    std::cout << "Merge sort custom comparator test passed!" << std::endl;
}

int main() {
    test_merge_sort();
    std::cout << "All tests passed." << std::endl;
    return 0;
}