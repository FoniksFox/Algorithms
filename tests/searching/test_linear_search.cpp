#include <iostream>

#include "searching/linear_search.hpp"
#include <vector>
#include <algorithm>
#include <cassert>


void test_basic_linear_search() {
    std::vector<int> vec = {1, 3, 5, 7, 9};
    auto it = algorithms::searching::linear_search(vec.begin(), vec.end(), 5);
    assert(it != vec.end());
    assert(*it == 5);

    auto it2 = algorithms::searching::linear_search(vec.begin(), vec.end(), 10);
    assert(it2 == vec.end());

    std::cout << "Basic linear search tests passed." << std::endl;
}

void test_linear_search_with_predicate() {
    std::vector<int> vec = {1, 3, 5, 7, 9};

    auto it = algorithms::searching::linear_search_if(vec.begin(), vec.end(), [](int x) { return x > 6; });
    assert(it != vec.end());
    assert(*it == 7);

    auto it2 = algorithms::searching::linear_search_if(vec.begin(), vec.end(), [](int x) { return x > 10; });
    assert(it2 == vec.end());

    std::cout << "Linear search with predicate tests passed." << std::endl;
}

int main() {
    test_basic_linear_search();
    test_linear_search_with_predicate();
    std::cout << "All tests passed." << std::endl;
    return 0;
}