#include<bits/stdc++.h>

using namespace std;

class AVLTree {
private:
    class Node {
    public:
        int data;
        int height;
        Node *left;
        Node *right;

        Node(int value) {
            data = value;
            height = 0;
            left = right = NULL;
        }
    };

    Node *root;
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

    void inOrder() {
        inOrder(root);
        cout << "\n";
    }

    void postOrder() {
        postOrder(root);
        cout << "\n";
    }

private:
    Node *insert(Node *root, int value) {
        if (root == NULL) {
            return new Node(value);
        }
        if (value < root->data) {
            root->left = insert(root->left, value);
        } else {
            root->right = insert(root->right, value);
        }
        setHeight(root);
        return balance(root);
    }

    Node *balance(Node *root) {
        if (leftHeavy(root)) {
            if (balanceFactor(root->left) < 0) {
                root->left = rotateLeft(root->left);
            }
            return rotateRight(root);
        } else if (rightHeavy(root)) {
            if (balanceFactor(root->right) > 0) {
                root->right = rotateRight(root->right);
            }
            return rotateLeft(root);
        }
        return root;
    }

    Node *rotateLeft(Node *root) {
        Node *newRoot = root->right;
        root->right = newRoot->left;
        newRoot->left = root;
        setHeight(root);
        setHeight(newRoot);
        return newRoot;
    }

    Node *rotateRight(Node *root) {
        Node *newRoot = root->left;
        root->left = newRoot->right;
        newRoot->right = root;
        setHeight(root);
        setHeight(newRoot);
        return newRoot;
    }

    void setHeight(Node *node) {
        node->height = 1 + max(height(node->left), height(node->right));
    }

    int height(Node *node) {
        return (node == NULL ? -1 : node->height);
    }

    int balanceFactor(Node *node) {
        return (node == NULL ? 0 : height(node->left) - height(node->right));
    }

    bool leftHeavy(Node *node) {
        return balanceFactor(node) > 1;
    }

    bool rightHeavy(Node *node) {
        return balanceFactor(node) < -1;
    }

    void preOrder(Node *node) {
        if (node == NULL) return;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void inOrder(Node *node) {
        if (node == NULL) return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    void postOrder(Node *node) {
        if (node == NULL) return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
};

int main() {
    AVLTree tree = AVLTree();
    tree.insert(30);
    tree.insert(10);
    tree.insert(20);
    tree.preOrder();
    tree.inOrder();
    tree.postOrder();
    return 0;
}