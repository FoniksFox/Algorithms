#pragma once

#include <iterator>
#include <functional>
#include <algorithm>
#include <vector>

namespace algorithms {
namespace sorting {
    namespace detail {
        /**
         * @brief Merges two sorted ranges into one sorted range.
         * @tparam RandomIt Random access iterator type.
         * @tparam Compare Comparison function type.
         * @param first Beginning of first sorted range.
         * @param mid Beginning of second sorted range (end of first).
         * @param last End of second sorted range.
         * @param comp Comparison function.
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
     * @tparam RandomIt Random access iterator type.
     * @tparam Compare Comparison function type.
     * @param first The beginning of the range to sort.
     * @param last The end of the range to sort.
     * @param comp The comparison function to use (defaults to std::less).
     *
     * Time Complexity: O(n log n)
     * Space Complexity: O(n)
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
} // namespace sorting
} // namespace algorithms