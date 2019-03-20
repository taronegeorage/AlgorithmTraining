#include <iostream>
#include <vector>

#include "sort.hpp"

int main()
{
    int temp[5] = {4, 2, 1, 3, 0};
    const std::vector<int> test(temp, temp+5);

    std::vector<int> a(test.begin(), test.end());
    bubble_sort(a.begin(), a.end());
    for (auto i : a) 
        std::cout << i << ' ';
    std::cout << std::endl;

    std::vector<int> b(test.begin(), test.end());
    insertion_sort(b.begin(), b.end());
    for (auto i : b)
        std::cout << i << ' ';
    std::cout << std::endl;

    std::vector<int> c(test.begin(), test.end());
    selection_sort(c.begin(), c.end());
    for (auto i : c)
        std::cout << i << ' ';
    std::cout << std::endl;

    std::vector<int> d(test.begin(), test.end());
    shell_sort(d.begin(), d.end());
    for (auto i : d) 
        std::cout << i << ' ';
    std::cout << std::endl;

    std::vector<int> e(test.begin(), test.end());
    bubble_down_sort(e.begin(), e.end());
    for (auto i : d) 
        std::cout << i << ' ';
    std::cout << std::endl;

    return 0;
}