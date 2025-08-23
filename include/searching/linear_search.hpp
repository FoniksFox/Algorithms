#pragma once

#include <iterator>
#include <functional>
namespace algorithms {
namespace searching {
    /**
     * @brief Performs a linear search on a range of elements.
     * @tparam ForwardIt Iterator type.
     * @tparam T Type of the elements to search for.
     * @param first The beginning of the range.
     * @param last The end of the range.
     * @param value The value to search for.
     * @return The iterator to the found element, or last if not found.
     * 
     * Time Complexity: O(n)
     * Space Complexity: O(1)
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
     * @brief Performs a linear search on a range of elements using a predicate.
     * @tparam ForwardIt Iterator type.
     * @tparam T Type of the elements to search for.
     * @tparam Pred Type of the predicate function.
     * @param first The beginning of the range.
     * @param last The end of the range.
     * @param pred The predicate function to test each element.
     * @return The iterator to the found element, or last if not found.
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1)
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
}
}