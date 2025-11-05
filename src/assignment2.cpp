/*
Name: Egide Muhire
Admission Number: 219728
DBT 1301 - Practical Assignment 2
Implementation of a Binary Search Tree (BST).
*/
#include <iostream>
#include <vector>

using namespace std;

/*
Represents a Node in a BST, along with the left and right nodes.
*/
struct Node {
    /*
    Initialize the data to the given value, along with left and right pointers
    to null.
    */
    Node(int data) : data{data}, left{nullptr}, right{nullptr} {}

    int data;
    Node* left;
    Node* right;
};

// Root of the tree.
Node* root{nullptr};

// Number of leaf nodes.
int leafCount{0};

// (Maximum) height of the tree reached so far.
int height{0};

// Current height of the tree at the current node.
int currentHeight{0};

// Keeps track of the node paths as a simple resizable stack.
vector<Node*> nodes{};

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
Reads and returns input from the keyboard (as an int).

This is used by menus to read user choices as well as values to feed into the
data structure classes.

The input is read as a raw string and converted into an int value.
If conversion fails, -1 is returned.
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

/*
Allows inserting of a node in the BST and returns a pointer to the insertion
point.
*/
Node* insertNode(Node* node, int data) {
    // Root node is empty - create and return a new one with data.
    if (!node) return new Node(data);

    // Data is less than the root node - perform a left insertion on left node
    if (data < node->data) {
        node->left = insertNode(node->left, data);
    }

    // Data is greater than root node - perform a right insertion on right node
    if (data > node->data) {
        node->right = insertNode(node->right, data);
    }

    return node;
}

// Main menu forward declaration
void showMainMenu();

/*
Displays inorder traversal of the BST.
*/
void showInOrderTraversal(Node* node) {
    if (!node) return;

    showInOrderTraversal(node->left);  // 1 - Recursively visit left node
    cout << node->data << " ";         // 2 - Visit root
    showInOrderTraversal(node->right); // 3 - Recursively visit right node
}

/*
Displays preorder traversal of the BST.
*/
void showPreOrderTraversal(Node* node) {
    if (!node) return;

    cout << node->data << " ";          // 1 - Visit root
    showPreOrderTraversal(node->left);  // 2 - Recursively visit left node
    showPreOrderTraversal(node->right); // 3 - Recursively visit right node
}

/*
Displays postorder traversal of the BST.
*/
void showPostOrderTraversal(Node* node) {
    if (!node) return;

    showPostOrderTraversal(node->left);  // 1 - Recursively visit left node
    showPostOrderTraversal(node->right); // 2 - Recursively visit right node
    cout << node->data << " ";           // 3 - Visit root
}

/*
Displays a menu for BST traversal operations (Inorder, preorder and postorder).
*/
void showTraversalsMenu() {
    // Show the menu and prompt the user for a valid choice.
    int choice = -1;
    do {
        showTitle("BST Traversals");

        cout << "\t1 - Inorder.\n";
        cout << "\t2 - Preorder.\n";
        cout << "\t3 - Postorder.\n";
        cout << "\t0 - Back.\n";

        choice = getInput();
    } while (!isValid(choice, 0, 3));

    switch (choice) {
        case 1: { // Inorder traversal.
            showTitle("Inorder Traversal", false);
            cout << "[ ";
            showInOrderTraversal(root);
            cout << "]";
            showTraversalsMenu();
            break;
        }
        case 2: { // Preorder traversal.
            showTitle("Preorder Traversal", false);
            cout << "[ ";
            showPreOrderTraversal(root);
            cout << "]";
            showTraversalsMenu();
            break;
        }
        case 3: { // Postorder traversal.
            showTitle("Postorder Traversal", false);
            cout << "[ ";
            showPostOrderTraversal(root);
            cout << "]";
            showTraversalsMenu();
            break;
        }
        case 0: { // Back to main menu
            showMainMenu();
            break;
        }
    }

    cout << '\n';
}

/*
Counts and displays the number of leaf nodes.
*/
void showLeafNodesCount(Node* node) {
    if (!node) return; // Return if root node is empty

    // Root is a leaf node (has no children), so show its data and add to count
    if (!node->left && !node->right) {
        cout << node->data << ' '; // Show leaf node data
        ++leafCount;               // Increment leaf node count
        return;
    }

    // Recursively count and show the leaf nodes in the left and right subtrees.
    showLeafNodesCount(node->left);
    showLeafNodesCount(node->right);
}

/*
Calculates the BST tree height.
*/
void calculateHeight(Node* node) {
    // The current node (left or right child) is null, go back up one height
    if (!node) {
        --currentHeight;
        return;
    }

    // The current node is a parent node.
    if (node->left || node->right) {
        ++currentHeight; // Increment the current height

        // Update the largest depth
        height = currentHeight > height ? currentHeight : height;
    }

    // Recursively visit the left and right nodes.
    calculateHeight(node->left);
    calculateHeight(node->right);
}

/*
Displays all the root-to-leaf paths.

// TODO: Fix with visiting algorithm marking nodes as visited.
*/
void showRootToLeafPaths(Node* node) {
    if (!node) return;

    nodes.push_back(node);

    if (!node->left && !node->right) {
        cout << "[ ";
        for (const auto& node : nodes) {
            cout << node->data << " ";
        }
        cout << "]\n";
        nodes.pop_back();
        return;
    }

    showRootToLeafPaths(node->left);
    showRootToLeafPaths(node->right);
}

/*
Displays the main menu, allowing the user to perform various BST operations.
*/
void showMainMenu() {
    // Show the menu and prompt the user for a valid choice.
    int choice = -1;
    do {
        showTitle("Main Menu");

        cout << "\t1 - Insert a node.\n";
        cout << "\t2 - Display traversals.\n";
        cout << "\t3 - Count / display number of leaf nodes.\n";
        cout << "\t4 - Display height.\n";
        cout << "\t5 - Print all root-to-leaf paths.\n";
        cout << "\t0 - Exit.\n";

        choice = getInput();
    } while (!isValid(choice, 0, 5));

    // Select operation
    switch (choice) {
        case 1: { // Node insertion
            cout << "Enter a value to insert\n";
            int value = getInput();
            root = insertNode(root, value);
            cout << "[ ";
            showInOrderTraversal(root);
            cout << "]";
            showMainMenu();
            break;
        }
        case 2: { // BST traversals
            showTraversalsMenu();
            break;
        }
        case 3: {          // Count and display number of leaf nodes.
            leafCount = 0; // reset leaf node count
            cout << "[ ";
            showLeafNodesCount(root);
            cout << "]";
            cout << "\nTotal leaf nodes: " << leafCount;
            if (leafCount == 0) {
                cout << " [empty]";
            }
            cout << '\n';
            showMainMenu();
            break;
        }
        case 4: {              // Display BST height
            height = 0;        // Reset height
            currentHeight = 0; // Reset current height
            calculateHeight(root);
            cout << "Tree height: " << height;
            if (height == 0) {
                cout << " [empty]";
            }
            cout << '\n';
            showMainMenu();
            break;
        }
        case 5: {          // Show all root-to-leaf paths.
            nodes.clear(); // Empty the path stack.
            showRootToLeafPaths(root);
            cout << '\n';
            showMainMenu();
            break;
        }
        case 0: { // Exit the program.
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