// Linear and binary search algorithms
#include <print>

void linearSearch(int a[], int n, int key) {
    int i = 0;
    int count = 0;
    for (i = 0; i < n; ++i) {
        if (a[i] == key) {
            std::println("The element is found at position {}", i);
            ++count;
        }
    }

    // Search was unsuccessful
    if (count == 0) {
        std::println("The element is not present in the array");
    }
}

void binarySearch(int a[], int low, int high, int key) {
    int mid;
    mid = (low + high) / 2;
    if (low <= high) {
        if (a[mid] == key)
            std::println("Element found at: {}", mid);
        else if (key < a[mid])
            binarySearch(a, low, mid - 1, key);
        else if (a[mid] < key)
            binarySearch(a, mid + 1, high, key);
    } else if (low > high)
        std::println("Unsuccessful search");
}

int main() {
    int i, n, key;
    n = 6;
    int a[10] = {1, 2, 4, 18, 22, 32, 44};

    key = 18;
    linearSearch(a, n, key);

    key = 23;
    linearSearch(a, n, key);

    int low, high;

    n = 5;
    low = 0;
    high = n - 1;
    int b[10] = {12, 14, 18, 22, 39};
    key = 22;
    binarySearch(a, low, high, key);

    key = 12;
    binarySearch(a, low, high, key);

    return 0;
}