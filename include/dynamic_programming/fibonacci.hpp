#pragma once

#include <concepts>
#include <stdexcept>

namespace algorithms {
namespace dynamic_programming {
    /**
     * @defgroup dp Dynamic Programming
     * @brief Algorithms that use dynamic programming techniques
     * 
     * @ingroup algorithms
     */

    /**
     * @concept Addable
     * @brief Concept for types that support addition and assignment.
     *
     * An Addable type must support the following operations:
     * - Addition: `a + b`
     * - Assignment: `a = b`
     */
    template<typename T>
    concept Addable = requires(T a, T b) {
        { a + b } -> std::convertible_to<T>;
        { a = b } -> std::same_as<T&>;
    };

    /**
     * @brief Computes the n-th Fibonacci number iteratively.
     * @param n The index of the Fibonacci number to compute.
     * @param startValue Addable starting value (F(0)).
     * @param nextValue Addable next value (F(1)).
     * @return The n-th Fibonacci number.
     *
     * Time complexity: O(n)
     * Space complexity: O(1)
     *
     * @note For consistent results, the addition operation (a + b) should be commutative: a + b == b + a.
     * 
     * @ingroup dp
     */
    template<Addable T = int>
    T fibonacci(int n, T startValue = 0, T nextValue = 1) {
        if (n < 0) throw std::invalid_argument("n must be non-negative");

        if (n == 0) return startValue;
        if (n == 1) return nextValue;

        T v0 = startValue;
        T v1 = nextValue;
        for (int i = 2; i <= n; ++i) {
            T temp = v1;
            v1 = v0 + v1;
            v0 = temp;
        }
        return v1;
    }
}
}