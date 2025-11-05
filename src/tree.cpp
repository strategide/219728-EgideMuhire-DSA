#include <print>

struct Node {
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }

    int data;
    Node* left;
    Node* right;
};

void inOrderTraversal(Node* node) {
    if (node == nullptr) return;

    inOrderTraversal(node->left);  // Visit left subtree
    std::print("{} ", node->data); // Visit current
    inOrderTraversal(node->right);
}

int main() {
    Node* node = new Node(1);
    // Left subtree
    node->left = new Node(2);
    node->left->left = new Node(4);
    node->left->right = new Node(5);

    // Right subtree
    node->right = new Node(3);
    std::println("In order traversal of the tree:");
    inOrderTraversal(node);

    return 0;
}