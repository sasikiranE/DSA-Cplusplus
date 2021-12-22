#include<bits/stdc++.h>
using namespace std;

class LinkedList {

private:

	class Node {

	public:

		int data;
		Node* next;

		Node(int value) {
			data = value;
			next = NULL;
		}

	};

	Node* head;
	Node* tail;
	int count;

public:

	LinkedList() {
		head = tail = NULL;
		count = 0;
	}

	int size() {
		return count;
	}

	void addLast(int value) {
		Node* newNode = new Node(value);
		if (head == NULL) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		count++;
	}

	void addFirst(int value) {
		Node* newNode = new Node(value);
		if (head == NULL) {
			head = tail = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
		count++;
	}

	void removeFirst() {
		if (head == NULL) {
			return;
		}
		else if (head == tail) {
			Node* temp = head;
			head = tail = NULL;
			delete temp;
		}
		else {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		count++;
	}

	void removeLast() {
		if (head == NULL) {
			return;
		}
		else if (head == tail) {
			Node* temp = head;
			head = tail = NULL;
			delete temp;
		}
		else {
			Node* curr = head;
			while (curr->next != tail) {
				curr = curr->next;
			}
			Node* temp = tail;
			curr->next = NULL;
			tail = curr;
			delete temp;
		}
		count--;
	}

	int indexOf(int target) {
		Node* curr = head;
		int idx = 0;
		while (curr != NULL) {
			if (curr->data == target) {
				return idx;
			}
			idx++;
			curr = curr->next;
		}
		return -1;
	}

	bool contains(int target) {
		return indexOf(target) != -1;
	}

	void print() {
		Node* curr = head;
		while (curr != NULL) {
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << "\n";
	}
};


int main() {
	LinkedList nums = LinkedList();
	return 0;
}