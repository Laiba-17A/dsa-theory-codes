#include <iostream>
#include <algorithm> // for max()
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    int height;
    Node(int v) {
        value = v;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

int height(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

int getBalanceFactor(Node* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

Node* insertAVL(Node* node, int value) {
    if (node == nullptr)
        return new Node(value);

    if (value < node->value)
        node->left = insertAVL(node->left, value);
    else if (value > node->value)
        node->right = insertAVL(node->right, value);
    else {
        cout << "No duplicate values allowed: " << value << "\n";
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));
    int bf = getBalanceFactor(node);

    if (bf > 1 && value < node->left->value)
        return rightRotate(node);

    if (bf < -1 && value > node->right->value)
        return leftRotate(node);

    if (bf > 1 && value > node->left->value) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (bf < -1 && value < node->right->value) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inorder(Node* node) {
    if (node == nullptr)
        return;
    inorder(node->left);
    cout << node->value << " ";
    inorder(node->right);
}

int main() {
    Node* root = nullptr;
    int values[] = {50, 30, 20, 10, 5, 40, 60, 70};
    for (int i = 0; i < 8; i++)
        root = insertAVL(root, values[i]);

    cout << "Inorder traversal (sorted): ";
    inorder(root);
    cout << "\n";

    cout << "Balance factors (inorder):\n";
    function<void(Node*)> printBF = [&](Node* n) {
        if (n == nullptr) return;
        printBF(n->left);
        cout << "Node " << n->value << " -> BF = " << getBalanceFactor(n) << "\n";
        printBF(n->right);
    };
    printBF(root);

    return 0;
}
