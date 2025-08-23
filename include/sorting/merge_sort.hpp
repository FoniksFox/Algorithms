#pragma once

#include <iterator>
#include <functional>
#include <algorithm>
#include <vector>

namespace algorithms {
namespace sorting {
    /**
     * @addtogroup sorting
     * @{
     */
    
    namespace detail {
        /**
         * @brief Merges two sorted ranges into one sorted range.
         * 
         * Helper function that merges two consecutive sorted ranges [first, mid) and [mid, last)
         * into a single sorted range [first, last). Uses temporary storage for the merge operation.
         * 
         * @tparam RandomIt Random access iterator type
         * @tparam Compare Comparison function type
         * @param first Beginning of first sorted range
         * @param mid Beginning of second sorted range (end of first)
         * @param last End of second sorted range
         * @param comp Comparison function
         * 
         * @pre [first, mid) and [mid, last) must be sorted according to comp
         * @post [first, last) is sorted according to comp
         */
        template<typename RandomIt, typename Compare>
        void merge(RandomIt first, RandomIt mid, RandomIt last, Compare comp) {
            using ValueType = typename std::iterator_traits<RandomIt>::value_type;
            
            // Create temporary storage for the merge
            std::vector<ValueType> temp;
            temp.reserve(std::distance(first, last));
            
            auto left = first;
            auto right = mid;
            
            // Merge the two sorted ranges
            while (left != mid && right != last) {
                if (comp(*left, *right)) {
                    temp.push_back(*left);
                    ++left;
                } else {
                    temp.push_back(*right);
                    ++right;
                }
            }
            
            // Copy remaining elements from left range
            while (left != mid) {
                temp.push_back(*left);
                ++left;
            }
            
            // Copy remaining elements from right range
            while (right != last) {
                temp.push_back(*right);
                ++right;
            }
            
            // Copy merged result back to original range
            std::copy(temp.begin(), temp.end(), first);
        }
    }
    
    /**
     * @brief Sorts a range of elements using the merge sort algorithm.
     * 
     * Merge sort is a divide-and-conquer algorithm that recursively divides the range
     * into halves, sorts each half, and then merges the sorted halves back together.
     * It provides guaranteed O(n log n) performance regardless of input data.
     * 
     * @tparam RandomIt Random access iterator type that must provide:
     *   - Random access capabilities (arithmetic operations)
     *   - Value type must be copy constructible and comparable using Compare function
     * @tparam Compare Comparison function type compatible with `bool(T, T)`
     * 
     * @param first Iterator to the beginning of the range to sort
     * @param last Iterator to the end of the range to sort
     * @param comp Comparison function object (defaults to std::less)
     * 
     * @par Complexity:
     * - Time: O(n log n) in all cases (best, average, worst)
     * - Space: O(n) for temporary storage during merging
     * 
     * @par Algorithm Properties:
     * - Stable: Yes (equal elements maintain relative order)
     * - Not in-place: No (requires O(n) extra memory)
     * - Not adaptive: No (performance is same regardless of input order)
     * - Predictable performance makes it good for real-time systems
     * 
     * @par Example:
     * ```cpp
     * std::vector<int> data = {64, 34, 25, 12, 22, 11, 90};
     * algorithms::sorting::merge_sort(data.begin(), data.end());
     * // data is now {11, 12, 22, 25, 34, 64, 90}
     * ```
     * 
     * @ingroup sorting
     */
    template<typename RandomIt, typename Compare = std::less<>>
    void merge_sort(RandomIt first, RandomIt last, Compare comp = {}) {
        static_assert(std::is_same_v<typename std::iterator_traits<RandomIt>::iterator_category,
                      std::random_access_iterator_tag> ||
                      std::is_base_of_v<std::random_access_iterator_tag,
                                       typename std::iterator_traits<RandomIt>::iterator_category>,
                      "Iterator must be a random access iterator for merge sort.");
        
        auto distance = std::distance(first, last);
        if (distance <= 1) return;  // Base case: 0 or 1 element
        
        auto mid = std::next(first, distance / 2);
        
        // Recursively sort both halves
        merge_sort(first, mid, comp);
        merge_sort(mid, last, comp);
        
        // Merge the sorted halves
        detail::merge(first, mid, last, comp);
    }

    /** @} */ // end of sorting group

} // namespace sorting
} // namespace algorithms