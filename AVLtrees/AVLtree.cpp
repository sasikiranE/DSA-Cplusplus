#include<bits/stdc++.h>
using namespace std;

class AVLTree {
private:
    class Node {
    public:
        int data;
        int height;
        Node* left;
        Node* right;
        Node(int value) {
            data = value;
            height = 0;
            left = right = NULL;
        }
    };
    Node* root;
public:
    AVLTree() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void preOrder() {
        preOrder(root);
        cout << "\n";
    }
private:
    Node* insert(Node* root, int value) {
        if (root == NULL) {
            return new Node(value);
        }
        if (value < root->data) {
            root->left = insert(root->left, value);
        }
        else {
            root->right = insert(root->right, value);
        }
        root->height = 1 + max(height(root->left), height(root->right));
        balance(root);
        return root;
    }

    void balance(Node* root) {
        if (leftHeavy(root)) {
            if (balanceFactor(root->left) < 0) {
                cout << "left rotate " << root->left->data << "\n";
            }
            cout << "right rotate " << root->data << "\n";
        }
        else if (rightHeavy(root)) {
            if (balanceFactor(root->right) > 0) {
                cout << "right rotate " << root->right->data << "\n";
            }
            cout << "left rotate " << root->data << "\n";
        }
    }

    int height(Node* node) {
        return (node == NULL ? -1 : node->height);
    }

    int balanceFactor(Node* node) {
        return (node == NULL ? 0 : height(node->left) - height(node->right));
    }

    bool leftHeavy(Node* node) {
        return balanceFactor(node) > 1;
    }

    bool rightHeavy(Node* node) {
        return balanceFactor(node) < -1;
    }

    void preOrder(Node* node) {
        if (node == NULL) return;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
};

int main() {
    AVLTree tree = AVLTree();
    tree.insert(10);
    tree.insert(30);
    tree.insert(20);
    return 0;
}