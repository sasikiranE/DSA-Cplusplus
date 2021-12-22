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
			tail = curr;
			tail->next = NULL;
			delete temp;
		}
		count--;
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
	for (int i = 1; i <= 5; i++) {
		nums.addLast(i);
	}
	nums.removeLast();
	nums.print();
	return 0;
}