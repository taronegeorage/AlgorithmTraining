#include <iostream>
#include <vector>

#include "binary_search.hpp"


template <typename VecT, typename T = typename VecT::value_type>
void test_bsearch(const VecT& test, T target) {
    auto it = binary_search_(test.begin(), test.end(), target);
    std::cout << std::distance(test.begin(), it) << std::endl;
}


int main(){
    int a[14] = {0, 0, 1, 2, 3, 4, 4, 5, 5, 5, 5, 5, 6, 7};
    std::vector<int> test(a, a+14);
    test_bsearch(test, 8);                        // 14
    test_bsearch(test, -1);                       // 14
    test_bsearch(test, 0);                        // 0, 1
    test_bsearch(test, 4);                        // 5, 6
    test_bsearch(test, 5);                        // 7, 8, 9, 10, 11
    test_bsearch(test, 7);                        // 13
    test_bsearch(test, 1);
    return 0;
}