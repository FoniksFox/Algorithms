#include <iostream>

#include "searching/binary_search.hpp"
#include <vector>
#include <algorithm>
#include <cassert>

void test_basic_binary_search() {
    std::vector<int> vec = {1, 3, 5, 7, 9};
    auto it = algorithms::searching::binary_search(vec.begin(), vec.end(), 5);
    assert(it != vec.end());
    assert(*it == 5);

    auto it2 = algorithms::searching::binary_search(vec.begin(), vec.end(), 10);
    assert(it2 == vec.end());

    std::cout << "Basic binary search tests passed." << std::endl;
}

void test_equal_range() {
    std::vector<int> vec = {1, 3, 5, 7, 9};

    auto [first, last] = algorithms::searching::equal_range(vec.begin(), vec.end(), 5);
    assert(first != last);
    assert(*first == 5);
    assert(std::next(first) == last);

    auto [first2, last2] = algorithms::searching::equal_range(vec.begin(), vec.end(), 10);
    assert(first2 == last2);

    std::vector<int> vec2 = {1, 3, 5, 5, 5, 7, 9};

    auto [first3, last3] = algorithms::searching::equal_range(vec2.begin(), vec2.end(), 5);
    assert(first3 != last3);
    assert(*first3 == 5);
    assert(*last3 == 7);
    assert(std::distance(first3, last3) == 3);

    auto [first4, last4] = algorithms::searching::equal_range(vec2.begin(), vec2.end(), 10);
    assert(first4 == last4);

    std::cout << "Equal range tests passed." << std::endl;
}

int main() {
    test_basic_binary_search();
    test_equal_range();
    std::cout << "All tests passed." << std::endl;
    return 0;
}