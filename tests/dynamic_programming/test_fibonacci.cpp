#include <iostream>

#include "dynamic_programming/fibonacci.hpp"
#include <cassert>

void test_fibonacci_int() {
    int f0 = algorithms::dynamic_programming::fibonacci(0);
    assert(f0 == 0);
    int f1 = algorithms::dynamic_programming::fibonacci(1);
    assert(f1 == 1);
    int f2 = algorithms::dynamic_programming::fibonacci(2);
    assert(f2 == 1);
    int f3 = algorithms::dynamic_programming::fibonacci(3);
    assert(f3 == 2);
    int f4 = algorithms::dynamic_programming::fibonacci(4);
    assert(f4 == 3);
    int f5 = algorithms::dynamic_programming::fibonacci(5);
    assert(f5 == 5);
    int f6 = algorithms::dynamic_programming::fibonacci(6);
    assert(f6 == 8);
    int f7 = algorithms::dynamic_programming::fibonacci(7);
    assert(f7 == 13);
    int f8 = algorithms::dynamic_programming::fibonacci(8);
    assert(f8 == 21);
    int f9 = algorithms::dynamic_programming::fibonacci(9);
    assert(f9 == 34);
    int f10 = algorithms::dynamic_programming::fibonacci(10);
    assert(f10 == 55);

    std::cout << "All basic Fibonacci tests passed!" << std::endl;
}

void test_fibonacci_float() {
    float f0 = algorithms::dynamic_programming::fibonacci<float>(0);
    assert(f0 == 0.0f);
    float f1 = algorithms::dynamic_programming::fibonacci<float>(1);
    assert(f1 == 1.0f);
    float f2 = algorithms::dynamic_programming::fibonacci<float>(2);
    assert(f2 == 1.0f);
    float f3 = algorithms::dynamic_programming::fibonacci<float>(3);
    assert(f3 == 2.0f);
    float f4 = algorithms::dynamic_programming::fibonacci<float>(4);
    assert(f4 == 3.0f);
    float f5 = algorithms::dynamic_programming::fibonacci<float>(5);
    assert(f5 == 5.0f);
    float f6 = algorithms::dynamic_programming::fibonacci<float>(6);
    assert(f6 == 8.0f);
    float f7 = algorithms::dynamic_programming::fibonacci<float>(7);
    assert(f7 == 13.0f);
    float f8 = algorithms::dynamic_programming::fibonacci<float>(8);
    assert(f8 == 21.0f);
    float f9 = algorithms::dynamic_programming::fibonacci<float>(9);
    assert(f9 == 34.0f);
    float f10 = algorithms::dynamic_programming::fibonacci<float>(10);
    assert(f10 == 55.0f);

    std::cout << "All Fibonacci float tests passed!" << std::endl;
}

void test_fibonacci_struct() {
    struct n {
        int value;
        n(int v) : value(v) {}
        n(const n& other) : value(other.value) {}
        n operator+(const n& other) const {
            return n(2 * value + 2 * other.value);
        }
        n& operator=(const n& other) {
            value = other.value;
            return *this;
        }
    };

    n f0 = algorithms::dynamic_programming::fibonacci<n>(0, n(1), n(2));
    assert(f0.value == 1);
    n f1 = algorithms::dynamic_programming::fibonacci<n>(1, n(1), n(2));
    assert(f1.value == 2);
    n f2 = algorithms::dynamic_programming::fibonacci<n>(2, n(1), n(2));
    assert(f2.value == 6);
    n f3 = algorithms::dynamic_programming::fibonacci<n>(3, n(1), n(2));
    assert(f3.value == 16);
    n f4 = algorithms::dynamic_programming::fibonacci<n>(4, n(1), n(2));
    assert(f4.value == 44);
    n f5 = algorithms::dynamic_programming::fibonacci<n>(5, n(1), n(2));
    assert(f5.value == 120);

    std::cout << "All Fibonacci struct tests passed!" << std::endl;
}

int main() {
    test_fibonacci_int();
    test_fibonacci_float();
    test_fibonacci_struct();
    std::cout << "All tests passed." << std::endl;
    return 0;
}