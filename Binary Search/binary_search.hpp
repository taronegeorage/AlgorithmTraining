#ifndef BSEARCH
#define BSEARCH

#include <iterator>
#include <functional>


// The algorithm works right with iterators that meet the ForwardIterator requirement, 
// but with a bad time complexity. For better performance, iterators should meet
// the RandomAccessIterator requirement.
template <typename IterT, typename ValueT = typename std::iterator_traits<IterT>::value_type, typename Compare = std::less<ValueT> >
IterT binary_search_(IterT first, IterT last, ValueT target, Compare comp = Compare()){
    IterT result = last;
    while(std::distance(first, last) > 0){
        IterT mid = first + std::distance(first, last)/2;
        if(comp(*mid, target)){
            first = mid + 1;
        }else if(comp(target, *mid)){
            last = mid;
        }else{
            result = mid;
            break;
        }
    }
    return result;
}


#endif