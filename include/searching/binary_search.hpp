#pragma once

#include <iterator>
#include <functional>

namespace algorithms {
namespace searching {
    /**
     * @brief Performs a binary search on a sorted range of elements.
     * @tparam Iterator Random access iterator type.
     * @tparam T Type of the elements to search for.
     * @param first The beginning of the sorted range.
     * @param last The end of the sorted range.
     * @param value The value to search for.
     * @param comp The comparison function to use (defaults to std::less).
     * @return Iterator to the found element, or last if not found.
     *
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
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
     * @tparam Iterator Random access iterator type.
     * @tparam T Type of the elements to search for.
     * @param first The beginning of the sorted range.
     * @param last The end of the sorted range.
     * @param value The value to search for.
     * @param comp The comparison function to use (defaults to std::less).
     * @return Pair of iterators [first_occurrence, last_occurrence], where last_occurrence is one past the last element of the range.
     *
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
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

} // namespace searching
} // namespace algorithms