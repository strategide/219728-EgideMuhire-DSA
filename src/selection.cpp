#include <print>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int* array, int size) {
    int i, j, iMin;
    for (i = 0; i < size - 1; ++i) {
        iMin = i; // get index of minimum data;
        for (j = i + 1; j < size; ++j) {
            if (array[j] < array[iMin]) {
                iMin = j;
            }
        }
        swap(array[i], array[iMin]);
    }
}

int main() {
    int size = 5;
    int array[5] = {12, 19, 55, 2, 16};

    std::println("Array before sorting");
    for (auto item : array) std::print("{} ", item);
    std::println();

    selectionSort(array, size);

    std::println("Array after sorting");
    for (auto item : array) std::print("{} ", item);
    std::println();

    return 0;
}