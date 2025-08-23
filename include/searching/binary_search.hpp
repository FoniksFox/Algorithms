#pragma once

#include <iterator>
#include <functional>
#include <utility>

namespace algorithms {
namespace searching {
    /**
     * @addtogroup searching
     * @{
     */

    /**
     * @brief Performs binary search on a sorted range of elements.
     * 
     * Binary search uses divide-and-conquer to efficiently find an element in a sorted range.
     * At each step, it compares the target with the middle element and eliminates half
     * of the remaining search space.
     * 
     * @tparam Iterator Random access iterator type that must provide:
     *   - Random access capabilities (arithmetic operations)
     *   - Value type must be comparable using Compare function
     * @tparam T Value type to search for, must be comparable with iterator's value type
     * @tparam Compare Comparison function type compatible with `bool(T, T)`
     * 
     * @param first Iterator to the beginning of the **sorted** range
     * @param last Iterator to the end of the **sorted** range
     * @param value The value to search for
     * @param comp Comparison function object (defaults to std::less)
     * @return Iterator to the found element, or last if not found
     * 
     * @pre The range [first, last) must be sorted according to comp
     * 
     * @par Complexity:
     * - Time: O(log n) where n is the distance between first and last
     * - Space: O(1) auxiliary space
     * 
     * @par Algorithm Properties:
     * - Requires sorted data
     * - Logarithmic time complexity
     * - Random access required for efficient midpoint calculation
     * 
     * @par Example:
     * ```cpp
     * std::vector<int> sorted_data = {1, 3, 5, 7, 9, 11, 13};
     * auto it = algorithms::searching::binary_search(sorted_data.begin(), sorted_data.end(), 7);
     * if (it != sorted_data.end()) {
     *     std::cout << "Found " << *it << " at position " << std::distance(sorted_data.begin(), it);
     * }
     * ```
     * 
     * @ingroup searching
     */
    template<typename Iterator, typename T, typename Compare = std::less<>>
    constexpr Iterator binary_search(Iterator first, Iterator last, const T& value, Compare comp = {}) {
        static_assert(std::is_same_v<typename std::iterator_traits<Iterator>::iterator_category,
                      std::random_access_iterator_tag> ||
                      std::is_base_of_v<std::random_access_iterator_tag, 
                                       typename std::iterator_traits<Iterator>::iterator_category>,
                      "Iterator must be a random access iterator for binary search.");
        
        while (first < last) {
            auto mid = first + (last - first) / 2;
            
            if (comp(*mid, value)) {
                // *mid < value, search right half
                first = mid + 1;
            } else if (comp(value, *mid)) {
                // value < *mid, search left half
                last = mid;
            } else {
                // *mid == value, found it
                return mid;
            }
        }
        
        return last; // Not found
    }

    /**
     * @brief Finds the range of all occurrences of a value in a sorted range.
     * 
     * Uses binary search to efficiently find the first and last occurrence of a value,
     * returning a pair of iterators that define the range [first_occurrence, one_past_last).
     * This is useful when the sorted range contains duplicate values.
     * 
     * @tparam Iterator Random access iterator type that must provide:
     *   - Random access capabilities (arithmetic operations)
     *   - Value type must be comparable using Compare function
     * @tparam T Value type to search for, must be comparable with iterator's value type
     * @tparam Compare Comparison function type compatible with `bool(T, T)`
     * 
     * @param first Iterator to the beginning of the **sorted** range
     * @param last Iterator to the end of the **sorted** range
     * @param value The value to search for
     * @param comp Comparison function object (defaults to std::less)
     * @return Pair of iterators [first_occurrence, one_past_last_occurrence)
     * 
     * @pre The range [first, last) must be sorted according to comp
     * 
     * @par Complexity:
     * - Time: O(log n) where n is the distance between first and last
     * - Space: O(1) auxiliary space
     * 
     * @par Return Value:
     * - If value is found: pair.first points to first occurrence, pair.second points one past last occurrence
     * - If value is not found: pair.first == pair.second, pointing to insertion position
     * 
     * @par Example:
     * ```cpp
     * std::vector<int> data = {1, 3, 5, 5, 5, 7, 9};
     * auto range = algorithms::searching::equal_range(data.begin(), data.end(), 5);
     * std::cout << "Found " << std::distance(range.first, range.second) << " occurrences";
     * // Output: Found 3 occurrences
     * ```
     * 
     * @ingroup searching
     */
    template<typename Iterator, typename T, typename Compare = std::less<>>
    constexpr std::pair<Iterator, Iterator> equal_range(Iterator first, Iterator last, const T& value, Compare comp = {}) {
        static_assert(std::is_same_v<typename std::iterator_traits<Iterator>::iterator_category,
                      std::random_access_iterator_tag> ||
                      std::is_base_of_v<std::random_access_iterator_tag, 
                                       typename std::iterator_traits<Iterator>::iterator_category>,
                      "Iterator must be a random access iterator for binary search.");
        
        // Find lower bound (first occurrence)
        auto lower = first;
        auto upper = last;
        while (lower < upper) {
            auto mid = lower + (upper - lower) / 2;
            if (comp(*mid, value)) {
                lower = mid + 1;
            } else {
                upper = mid;
            }
        }
        
        // Find upper bound (one past last occurrence)
        auto lower2 = first;
        auto upper2 = last;
        while (lower2 < upper2) {
            auto mid = lower2 + (upper2 - lower2) / 2;
            if (comp(value, *mid)) {
                upper2 = mid;
            } else {
                lower2 = mid + 1;
            }
        }
        
        return {lower, upper2};
    }

    /** @} */ // end of searching group

} // namespace searching
} // namespace algorithms