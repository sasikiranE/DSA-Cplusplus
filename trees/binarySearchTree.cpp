#include<bits/stdc++.h>
using namespace std;

class BinarySearchTree {

	class Node {
	public:

		int data;
		Node* left;
		Node* right;

		Node(int value) {
			data = value;
			left = right = NULL;
		}
	};

	Node* root;

public:

	BinarySearchTree() {
		root = NULL;
	}

	void insert(int value) {
		Node* newNode = new Node(value);
		if (root == NULL) {
			root = newNode;
			return;
		}
		Node* curr = root;
		while (true) {
			if (value < curr->data) {
				if (curr->left == NULL) {
					curr->left = newNode;
					return;
				}
				curr = curr->left;
			}
			else if (value > curr->data) {
				if (curr->right == NULL) {
					curr->right = newNode;
					return;
				}
				curr = curr->right;
			}
			else return;
		}
	}

	bool contains(int target) {
		Node* curr = root;
		while (curr != NULL) {
			if (target < curr->data) {
				curr = curr->left;
			}
			else if (target > curr->data) {
				curr = curr->right;
			}
			else return true;
		}
		return false;
	}

	int height() {
		return height(root);
	}

	int getMin() {
		if (root == NULL) {
			return INT_MAX;
		}
		Node* curr = root;
		while (curr->left != NULL) {
			curr = curr->left;
		}
		return curr->data;
	}

	int getMax() {
		if (root == NULL) {
			return INT_MIN;
		}
		Node* curr = root;
		while (curr->right != NULL) {
			curr = curr->right;
		}
		return curr->data;
	}

	bool equals(BinarySearchTree &other) {
		return equals(root, other.root);
	}

	bool isBinarySearchTree() {
		return isBinarySearchTree(root, INT_MIN, INT_MAX);
	}

	// Depth First Travesals.
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

	// Breadth First traversal
	void levelOrder() {
		if (root == NULL) return;
		queue<Node*> q;
		q.push(root);
		while (!q.empty()) {
			Node* curr = q.front();
			q.pop();
			cout << curr->data << " ";
			if (curr->left != NULL) q.push(curr->left);
			if (curr->right != NULL) q.push(curr->right);
		}
		cout << "\n";
	}

private:

	int height(Node* root) {
		if (root == NULL) return -1;
		if (root->left == NULL and root->right == NULL) return 0;
		return 1 + max(height(root->left), height(root->right));
	}

	bool equals(Node* root1, Node* root2) {
		if (root1 == NULL and root2 == NULL) {
			return true;
		}
		if (root1 != NULL and root2 != NULL) {
			return root1->data == root2->data and equals(root1->left, root2->left) and equals(root1->right, root2->right);
		}
		return false;
	}

	bool isBinarySearchTree(Node* root, int low, int high) {
		if (root == NULL) {
			return true;
		}
		if (root->data < low or root->data > high) {
			return false;
		}
		else {
			return isBinarySearchTree(root->left, low, root->data - 1) and isBinarySearchTree(root->right, root->data + 1, high);
		}
	}

	void preOrder(Node* root) {
		if (root == NULL) {
			return;
		}
		cout << root->data << " ";
		preOrder(root->left);
		preOrder(root->right);
	}

	void postOrder(Node* root) {
		if (root == NULL) {
			return;
		}
		postOrder(root->left);
		postOrder(root->right);
		cout << root->data << " ";
	}

	void inOrder(Node* root) {
		if (root == NULL) {
			return;
		}
		inOrder(root->left);
		cout << root->data << " ";
		inOrder(root->right);
	}

};


int main() {
	BinarySearchTree bst = BinarySearchTree();
	// bst.insert(7);
	// bst.insert(4);
	// bst.insert(9);
	// bst.insert(1);
	// bst.insert(5);
	// bst.insert(8);
	// bst.insert(10);
	return 0;
}