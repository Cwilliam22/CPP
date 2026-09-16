#include "iter.hpp"

void print(const int &n) {
    std::cout << n << " ";
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    const int const_arr[] = {1, 2, 3, 4, 5}; // const version
    size_t length = sizeof(arr) / sizeof(arr[0]);
    size_t length_const = sizeof(const_arr) / sizeof(const_arr[0]); // const version
    std::cout << "\033[36m--- " << "Array :" << " ---\033[0m" << std::endl;
    iter(arr, length, print);
    std::cout << std::endl;
    std::cout << "\033[36m--- " << "Const Array :" << " ---\033[0m" << std::endl; // const version
    iter(const_arr, length_const, print); // const version
    std::cout << std::endl;
    return (0);
}