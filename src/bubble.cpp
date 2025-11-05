// Bubble sort algorithm
#include <print>

void bubbleSort(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        bool swaps = 0;
        for (int j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swaps = true;
            }
        }
        if (!swaps) {
            break;
        }
    }
}

int main() {
    int n = 5;
    auto show = [](const auto& array) {
        for (auto item : array) {
            std::print("{} ", item);
        }
    };

    int array[5] = {67, 44, 82, 17, 20};
    std::println("Array before sorting");
    show(array);

    bubbleSort(array, n);
    std::println("\nArray after sorting");
    show(array);

    return 0;
}