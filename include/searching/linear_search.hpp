#pragma once

#include <iterator>
#include <functional>

namespace algorithms {
namespace searching {
    /**
     * @defgroup algorithms Algorithms Library
     * @brief Modern C++ implementation of fundamental algorithms
     */
    
    /**
     * @defgroup searching Searching Algorithms
     * @brief Collection of searching algorithms for sorted and unsorted data
     * @ingroup algorithms
     * @{
     */

    /**
     * @brief Performs linear search on a range of elements.
     * 
     * Linear search sequentially checks each element in the range until the target
     * value is found or the end of the range is reached. Works on any forward iterator.
     * 
     * @tparam Iterator Forward iterator type that must provide:
     *   - Forward iteration capabilities
     *   - Value type must be equality comparable with T
     * @tparam T Value type to search for, must be equality comparable with iterator's value type
     * 
     * @param first Iterator to the beginning of the range
     * @param last Iterator to the end of the range
     * @param value The value to search for
     * @return Iterator to the found element, or last if not found
     * 
     * @par Complexity:
     * - Time: O(n) where n is the distance between first and last
     * - Space: O(1) auxiliary space
     * 
     * @par Algorithm Properties:
     * - Works on unsorted data
     * - Sequential access pattern (cache-friendly for arrays)
     * - Early termination when element is found
     * 
     * @par Example:
     * ```cpp
     * std::vector<int> data = {1, 3, 5, 7, 9};
     * auto it = algorithms::searching::linear_search(data.begin(), data.end(), 5);
     * if (it != data.end()) {
     *     std::cout << "Found " << *it << " at position " << std::distance(data.begin(), it);
     * }
     * ```
     * 
     * @ingroup searching
     */
    template<typename Iterator, typename T>
    constexpr Iterator linear_search(Iterator first, Iterator last, const T& value) {
        static_assert(std::is_same_v<typename std::iterator_traits<Iterator>::iterator_category,
                      std::forward_iterator_tag> ||
                      std::is_base_of_v<std::forward_iterator_tag, typename std::iterator_traits<Iterator>::iterator_category>,
                      "Iterator must be at least a forward iterator.");

        for (auto it = first; it != last; ++it) {
            if (*it == value) {
                return it;
            }
        }

        return last;
    }

    /**
     * @brief Performs linear search with a custom predicate function.
     * 
     * Linear search that finds the first element satisfying a given predicate.
     * This is useful for more complex search criteria than simple equality.
     * 
     * @tparam Iterator Forward iterator type that must provide:
     *   - Forward iteration capabilities  
     *   - Value type must be compatible with the predicate
     * @tparam Predicate Unary predicate type compatible with `bool(ValueType)`
     * 
     * @param first Iterator to the beginning of the range
     * @param last Iterator to the end of the range
     * @param pred Predicate function that returns true for the desired element
     * @return Iterator to the first element satisfying the predicate, or last if none found
     * 
     * @par Complexity:
     * - Time: O(n) where n is the distance between first and last
     * - Space: O(1) auxiliary space
     * 
     * @par Algorithm Properties:
     * - Works on unsorted data
     * - More flexible than value-based search
     * - Early termination when matching element is found
     * 
     * @par Example:
     * ```cpp
     * std::vector<int> data = {1, 3, 5, 7, 9};
     * auto it = algorithms::searching::linear_search_if(data.begin(), data.end(), 
     *                                                  [](int x) { return x > 6; });
     * if (it != data.end()) {
     *     std::cout << "First element > 6: " << *it;  // Output: 7
     * }
     * ```
     * 
     * @ingroup searching
     */

    template<typename Iterator, typename Pred>
    constexpr Iterator linear_search_if(Iterator first, Iterator last, Pred pred) {
        static_assert(std::is_same_v<typename std::iterator_traits<Iterator>::iterator_category,
                      std::forward_iterator_tag> ||
                      std::is_base_of_v<std::forward_iterator_tag, typename std::iterator_traits<Iterator>::iterator_category>,
                      "Iterator must be at least a forward iterator.");

        for (auto it = first; it != last; ++it) {
            if (pred(*it)) {
                return it;
            }
        }

        return last;
    }

    /** @} */ // end of searching group

} // namespace searching
} // namespace algorithms