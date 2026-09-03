#include "iter.hpp"

void print(const int &n) {
    std::cout << n << " ";
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    size_t length = sizeof(arr) / sizeof(arr[0]);
    iter(arr, length, print);
    std::cout << std::endl;
    return (0);
}