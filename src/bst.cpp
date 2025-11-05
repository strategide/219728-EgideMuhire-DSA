// Binary search tree

#include <print>

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create a new node
Node* createNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Node* insertNode(Node* root, int data) {
    if (root == nullptr) return createNode(data);
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

Node* searchNode(Node* root, int key) {
    if (root == nullptr || root->data == key) return root;
    if (key < root->data) {
        return searchNode(root->left, key);
    } else {
        return searchNode(root->right, key);
    }
}

// Inorder traversal (Left -> Root -> Right)
void inOrderTraversal(Node* root) {
    if (root) {
        inOrderTraversal(root->left);
        std::print("{} ", root->data);
        inOrderTraversal(root->right);
    }
}

// Preorder traversal (Root -> Left -> Right)
void preOrderTraversal(Node* root) {
    if (root) {
        std::print("{} ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Postorder traversal (Left -> Right -> Root)
void postOrderTraversal(Node* root) {
    if (root) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        std::print("{} ", root->data);
    }
}

int main() {
    Node* root = nullptr;
    
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);
    std::println("Inorder traversal: ");
    inOrderTraversal(root);
    std::println();
    
    return 0;
}