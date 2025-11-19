/*
Name: Egide Muhire
Admission Number: 219728
DBT 1301 - Practical Assignment 3
Sorting and Searching an Array.
*/

#include <iostream>
#include <vector>

using namespace std;

/*
Shows a prompt and returns the entered data as an integer.
*/
int getInput() {
    cout << ">: "; // show input prompt

    string input;
    try {
        getline(cin, input);
        return stoi(input);
    } catch (std::exception& e) { // catch all by reference
        return -1;
    }
}

/*
Prompts the user for and returns the size of the array (greater than zero).
*/
int getArraySize() {
    int size = 0;
    do {
        cout << "Enter the array size (greater than zero)\n";
        size = getInput();
    } while (size < 1);

    return size;
}

/*
Ask the user to populate the array.
*/
void fillArray(std::vector<int>& values, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Enter a value: (" << (i + 1) << " / " << size << ")\n";
        int value = getInput();
        values.push_back(value);
    }
}

/*
Merges both left and right arrays into a single array (ascending order), while
returning the sorted array.
*/
std::vector<int> merge(std::vector<int>& left, std::vector<int>& right) {
    std::vector<int> result;
    int i = 0;
    int j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            result.push_back(left[i++]);
        } else {
            result.push_back(right[j++]);
        }
    }

    for (int start = i; start < left.size(); ++start) {
        result.push_back(left[start]);
    }

    for (int end = j; end < right.size(); ++end) {
        result.push_back(right[end]);
    }

    return result;
}

/*
Repeatedly subdivides the array into two halves until each half contains only
one element, then merges the halves back ensuring that the values are in
ascending order.
*/
std::vector<int> sort(std::vector<int> array) {
    if (array.size() == 1) return array; // already subdivided.

    int mid = array.size() / 2;          // Find midpoint.

    std::vector<int> left{array.begin(), array.begin() + mid}; // Left half
    std::vector<int> right{array.begin() + mid, array.end()};  // Right half

    // Recursively subdivide each half
    std::vector<int> sortedLeft = sort(left);
    std::vector<int> sortedRight = sort(right);

    // Merge the sorted halves, ensuring they're in the correct order.
    return merge(sortedLeft, sortedRight);
}

/*
Searches the given array (using binary search) and returns the index the value 
was found at or return -1 if it could not be found.
*/
int search(std::vector<int>& array, int low, int high, int value) {
    int mid = (low + high) / 2;
    if (low <= high) {
        if (value == array[mid]) {
            return mid;
        } else if (value < array[mid]) {
            return search(array, low, mid - 1, value);
        } else {
            return search(array, mid + 1, high, value);
        }
    } else {
        return -1;
    }
}

/*
Main entry for the program.
*/
int main() {

    // Get the size from the user.
    const int size = getArraySize();

    // Pre-allocate the array with the given size.
    std::vector<int> values;

    // Populate the array with user-provided values
    fillArray(values, size);

    // Show the values before sorting
    cout << "Values before sorting:\n";
    cout << "[ ";
    for (const int& i : values) cout << i << " ";
    cout << "]\n";

    // Sort the array using a merge sort algorithm and return the sorted array
    std::vector<int> sorted = sort(values);

    // Show the values after sorting
    cout << "Values after sorting:\n";
    cout << "[ ";
    for (const int& i : sorted) cout << i << " ";
    cout << "]\n";

    // Prompt the user for a search value
    cout << "Enter a value to search for:\n"; 
    int value = getInput();

    // Search the array for the value
    int low = 0;
    int high = sorted.size() - 1;
    int index = search(sorted, low, high, value);
    if (index == -1) {
        cout << "Value [" << value << "] could not be found in the array\n";
    } else {
        cout << "Value [" << value << "] was found at index: " << index << '\n';
    }

    return 0;
}