#ifdef BUCKET_SORT_HPP
#define BUCKET_SORT_HPP

#include <iterator>
#include <functional>
#include <algorithm>
#include <vector>

template <size_t BucketSize, typename IterT, typename T = typename std::iterator_traits<IterT>::value_type, typename Compare = std::less<T> >
void bucket_sort(IterT first, IterT last, Compare comp = Compare()){
    const T min = *std::min_element(first, last), max = *std::max_element(first, last);
}

# endif