/*
Name: Egide Muhire
Admission Number: 219728
DBT 1301 - CAT 2
*/

#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
Representation of a graph.
*/
struct Graph {
    // Initialize the graph with the appropriate queue size.
    Graph(int size) : adj(size) {}

    // Adds the given data to the adjacency matrix, connecting both sides.
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Performs a BFS traversal.
    void breadthFirstSearch() {
        int size = adj.size();
        std::vector<bool> visited(size, false);
        std::queue<int> queue;

        // Start with the first node.
        int src = 0;
        visited[src] = true;
        queue.push(src);

        while (!queue.empty()) {
            // Pop the node from the queue, and show its value.
            int current = queue.front();
            queue.pop();
            cout << current << " -> ";

            for (int& x : adj[current]) {
                if (!visited[x]) {
                    visited[x] = true; // Mark a node as visited and continue.
                    queue.push(x);
                }
            }
        }
    }

    std::vector<std::vector<int>> adj;
};

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
Shows a menu title (with an underline decoration).
*/
void showTitle(std::string_view title, bool showPrompt = true) {
    cout << '\n' << title << '\n';
    for (int i = 0; i < title.size(); ++i) {
        cout << '-';
    }
    cout << '\n';
    if (!showPrompt) return;

    cout << "Enter:\n";
}

/*
Returns 'true' if the given 'choice' is between the provided 'min' and 'max'
values (valid), 'false' otherwise (invalid).

This is used by menu functions to validate an entered menu choice.
*/
bool isValid(int choice, int min, int max) {
    if (choice < min || choice > max) {
        cerr << "Invalid choice [" << choice << "]. Please try again.\n";
        return false;
    }

    return true;
}

std::vector<int> performMergeSort() {
    // Ask person to enter in the array size.
    int size = 0;
    do {
        cout << "Enter the array size (greater than zero)\n";
        size = getInput();
    } while (size < 1);

    std::vector<int> values; // empty array

    // Populate the array
    for (int i = 0; i < size; ++i) {
        cout << "Enter a value: (" << (i + 1) << " / " << size << ")\n";
        int value = getInput();
        values.push_back(value);
    }

    auto show = [&](auto& array) {
        cout << "[ ";
        for (const auto& value : array) cout << value << " ";
        cout << "]\n";
    };

    // Show array before sorting
    cout << "Array before sorting:\n";
    show(values);

    // Lambda to merge the left and right arrays in a sorted manner.
    auto merge = [&](auto& left, auto& right) {
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
    };

    // Lambda to subdivide the array into two halves, sorting each on merging.
    std::function<std::vector<int>(std::vector<int>)> sort;
    sort = [&](std::vector<int> array) {
        if (array.size() == 1) return array; // already subdivided.

        int mid = array.size() / 2;          // Find the midpoint.

        std::vector<int> left{array.begin(), array.begin() + mid}; // Left half
        std::vector<int> right{array.begin() + mid, array.end()};  // Right half

        // Recursively subdivide each half
        std::vector<int> sortedLeft = sort(left);
        std::vector<int> sortedRight = sort(right);

        return merge(sortedLeft, sortedRight);
    };

    // Sort the array and return the sorted values.
    std::vector<int> sorted = sort(values);

    // Show the sorted array.
    cout << "Array after sorting:\n";
    show(sorted);

    // Return the sorted array
    return sorted;
}

/*
Searches the given array (using a binary search algorithm) and returns 'true'
if the value is found, 'false' if not.
*/
bool binarySearch(std::vector<int>& array, int low, int high, int value) {
    int mid = (low + high) / 2;
    if (low <= high) {
        if (value == array[mid]) {
            return true;
        } else if (value < array[mid]) {
            return binarySearch(array, low, mid - 1, value);
        } else {
            return binarySearch(array, mid + 1, high, value);
        }
    } else {
        return false;
    }
}

void performBFS() {
    // Create a graph and add some data edges to it
    Graph graph{7};

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(3, 4);
    graph.addEdge(2, 5);
    graph.addEdge(2, 6);
    graph.addEdge(5, 6);

    graph.breadthFirstSearch();
}

/*
Displays the main menu for the program.
*/
void showMainMenu() {
    // Show the menu and prompt the user for a valid choice.
    int choice = -1;
    do {
        showTitle("Main Menu");

        cout << "\t1 - Merge Sort.\n";
        cout << "\t2 - Binary Search.\n";
        cout << "\t3 - Breadth First Search (BFS).\n";
        cout << "\t0 - Exit.\n";

        choice = getInput();
    } while (!isValid(choice, 0, 3));

    static std::vector<int> values;

    // Select operation
    switch (choice) {
        case 1: { // Merge Sort
            auto sorted = performMergeSort();
            values.clear();
            values.insert(values.begin(), sorted.begin(), sorted.end());
            showMainMenu();
            break;
        }
        case 2: { // Binary Search
            // Ensure that the array is not empty.
            if (values.empty()) {
                cout << "Please populate the array first (with option 1 "
                        "above).\n";
                showMainMenu();
                break;
            }

            // Ask the user for an search value.
            cout << "Enter a value to search for:\n";
            int value = getInput();

            /*
            Using the sorted array (above), search for the value (binary search)
            and show "Found" or "Not Found" if the value is found or not.
            */
            int low = 0;
            int high = values.size() - 1;
            bool found = binarySearch(values, low, high, value);
            if (found) {
                cout << "Found\n";
            } else {
                cout << "Not Found\n";
            }

            showMainMenu();
            break;
        }
        case 3: { // Breadth First Search (BFS)
            performBFS();
            showMainMenu();
            break;
        }
        case 0: {
            cout << "Goodbye.\n";
            exit(0);
            break;
        }
    }
}

// Main program entry.
int main() {
    showMainMenu();
    return 0;
}
