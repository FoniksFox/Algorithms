#pragma once

#include <iterator>
#include <functional>
#include <algorithm>

namespace algorithms {
namespace sorting {
    /**
     * @defgroup sorting Sorting Algorithms
     * @brief Collection of sorting algorithms with different performance characteristics
     * @ingroup algorithms
     * @{
     */

    /**
     * @brief Sorts a range of elements using the bubble sort algorithm.
     * 
     * Bubble sort repeatedly steps through the list, compares adjacent elements
     * and swaps them if they are in the wrong order. The pass through the list
     * is repeated until the list is sorted. This implementation includes the
     * optimization to stop early if no swaps occur.
     * 
     * @tparam Iterator Bidirectional iterator type that must provide:
     *   - Bidirectional iteration capabilities
     *   - Value type must be swappable and comparable using Compare function
     * @tparam Compare Comparison function type compatible with `bool(T, T)`
     * 
     * @param first Iterator to the beginning of the range to sort
     * @param last Iterator to the end of the range to sort
     * @param comp Comparison function object (defaults to std::less)
     * 
     * @par Complexity:
     * - Time: O(n²) average and worst case, O(n) best case (already sorted)
     * - Space: O(1) auxiliary space
     * 
     * @par Algorithm Properties:
     * - Stable: Yes (equal elements maintain relative order)
     * - In-place: Yes (O(1) extra memory)
     * - Adaptive: Yes (performs better on nearly sorted data)
     * - Simple implementation but inefficient for large datasets
     * 
     * @par Example:
     * ```cpp
     * std::vector<int> data = {64, 34, 25, 12, 22, 11, 90};
     * algorithms::sorting::bubble_sort(data.begin(), data.end());
     * // data is now {11, 12, 22, 25, 34, 64, 90}
     * ```
     * 
     * @ingroup sorting
     */
    template<typename Iterator, typename Compare = std::less<>>
    void bubble_sort(Iterator first, Iterator last, Compare comp = {}) {
        static_assert(std::is_same_v<typename std::iterator_traits<Iterator>::iterator_category,
                      std::random_access_iterator_tag> ||
                      std::is_base_of_v<std::bidirectional_iterator_tag,
                                       typename std::iterator_traits<Iterator>::iterator_category>,
                      "Iterator must be a bidirectional iterator for bubble sort.");

        if (first == last) return;

        bool swapped;
        auto end = last;

        do {
            swapped = false;
            auto current = first;
            auto next = std::next(current);

            while (next != end) {
                if (comp(*next, *current)) {
                    std::iter_swap(current, next);
                    swapped = true;
                }
                current = next;
                ++next;
            }
            --end;
        } while (swapped && end != first);
    }

    /** @} */ // end of sorting group

} // namespace sorting
} // namespace algorithms