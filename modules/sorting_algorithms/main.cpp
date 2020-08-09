// Copyright 2020 Vikhrev Ivan

#include <iostream>
#include <vector>

using std::cout;
using std::vector;
// O(n^2)
void insertionSort(int* l, int* r) {
    int size = r - l;

    for (int i = 1; i < size; ++i) {
        int curr = *(l + i);
        int j = i-1;
        while (j >= 0 && *(l + j) > curr) {
            *(l + j + 1) = *(l + j);
            --j;
        }
        *(l + j + 1) = curr;
    }
}

int main(int argc, char** argv) {
    // int n = 10;
    // int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int b[] = { 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0 };
    // int c[] = {2, 3, 5, 6, 1, 11, 18, 0, -1, -19};

    // insertionSort(a, a + n);
    // insertionSort(b, b + n);
    // insertionSort(c, c + n);
    // for (int i = 0; i < n; ++i) {
    //     std::cout << a[i] << " ";
    // }
    // std::cout << std::endl;

    // for (int i = 0; i < n; ++i) {
    //     std::cout << b[i] << " ";
    // }
    // std::cout << std::endl;
    // for (int i = 0; i < n; ++i) {
    //     std::cout << c[i] << " ";
    // }
    return 0;
}
