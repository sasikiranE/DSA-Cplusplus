#include<bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

class Trie {

	class Node {
	public:
		Node* children[ALPHABET_SIZE];
		bool isEndOfWord;

		Node() {
			for (int i = 0; i < ALPHABET_SIZE; i++) {
				children[i] = NULL;
			}
			isEndOfWord = false;
		}
	};

	Node* root;
public:

	Trie() {
		root = new Node();
	}

	void insert(string word) {
		Node* curr = root;
		for (char ch : word) {
			int index = ch - 'a';
			if (curr->children[index] == NULL) {
				curr->children[index] = new Node();
			}
			curr = curr->children[index];
		}
		curr->isEndOfWord = true;
	}

	bool search(string word) {
		Node* curr = root;
		for (char ch : word) {
			int index = ch - 'a';
			if (curr->children[index] == NULL) {
				return false;
			}
			curr = curr->children[index];
		}
		return curr->isEndOfWord;
	}

	vector<string> findWords(string prefix) {
		vector<string> words;
		if (prefix == "") return words;
		Node* lastNode = findLastNodeOf(prefix);
		findWords(lastNode, prefix, words);
		return words;
	}

	void traverse() {
		traverse(root);
	}

private:

	void traverse(Node* root) {
		for (int i = 0; i < ALPHABET_SIZE; i++) {
			if (root->children[i] == NULL) continue;
			cout << char(i + 'a') << endl;
			traverse(root->children[i]);
		}
	}

	void findWords(Node* root, string prefix, vector<string> &words) {
		if (root == NULL) return;
		if (root->isEndOfWord) {
			words.push_back(prefix);
		}
		for (int i = 0; i < ALPHABET_SIZE; i++) {
			if (root->children[i] != NULL) {
				char ch = i + 'a';
				findWords(root->children[i], prefix + ch, words);
			}
		}
	}

	Node* findLastNodeOf(string prefix) {
		Node* curr = root;
		for (char ch : prefix) {
			int index = ch - 'a';
			if (curr->children[index] == NULL) return NULL;
			curr = curr->children[index];
		}
		return curr;
	}
};


int main() {
	Trie tree = Trie();
	tree.insert("car");
	tree.insert("card");
	tree.insert("care");
	tree.insert("careful");
	tree.insert("egg");
	vector<string> ans = tree.findWords("ca");
	for (auto & s : ans) {
		cout << s << "\n";
	}
	return 0;
}