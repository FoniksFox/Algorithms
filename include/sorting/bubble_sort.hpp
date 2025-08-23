#pragma once

#include <iterator>
#include <functional>
#include <algorithm>

namespace algorithms {
namespace sorting {
    /**
     * @brief Sorts a range of elements using the bubble sort algorithm.
     * @tparam Iterator Random access iterator type.
     * @param first The beginning of the range to sort.
     * @param last The end of the range to sort.
     * @param comp The comparison function to use (defaults to std::less).
     *
     * Time Complexity: O(n^2)
     * Space Complexity: O(1)
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
}
}