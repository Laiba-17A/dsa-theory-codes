#include <iostream>
#include <algorithm> // for max()
#include <cmath>     // for abs()
using namespace std;

// Node structure
struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int val) : key(val), left(NULL), right(NULL) {}
};

// Insert function for BST
Node* insert(Node* root, int key) {
    if (root == NULL)
        return new Node(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    return root;
}

// Function to calculate height of a node
int height(Node* root) {
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

// Function to get balance factor of a node
int getBalanceFactor(Node* root) {
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

// Function to check and print if each node is balanced or imbalanced
void checkBalance(Node* root) {
    if (root == NULL)
        return;

    // Inorder traversal (Left ? Root ? Right)
    checkBalance(root->left);

    int bf = getBalanceFactor(root);
    cout << "Node " << root->key << " ? Balance Factor = " << bf;

    if (abs(bf) <= 1)
        cout << " ? Balanced" << endl;
    else
        cout << " ?? Imbalanced" << endl;

    checkBalance(root->right);
}

// Function to check if the *whole tree* is balanced
bool isTreeBalanced(Node* root) {
    if (root == NULL)
        return true;

    int bf = getBalanceFactor(root);
    if (abs(bf) > 1)
        return false;

    // Check recursively for left and right subtrees
    return isTreeBalanced(root->left) && isTreeBalanced(root->right);
}

int main() {
    Node* root = NULL;

    // Construct BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 10);  // Adding extra nodes to make imbalance
    root = insert(root, 5);   // Deepen the imbalance on the left side

    cout << "?? Checking balance status of each node:\n";
    checkBalance(root);

    cout << "\n?? Checking if the entire tree is balanced:\n";
    if (isTreeBalanced(root))
        cout << "? The tree is balanced." << endl;
    else
        cout << "?? The tree is imbalanced." << endl;

    return 0;
}

