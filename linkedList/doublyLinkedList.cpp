#include<bits/stdc++.h>
using namespace std;

class DoublyLinkedList {
private:

	class Node {
	public:
		int data;
		Node* prev;
		Node* next;

		Node(int value) {
			data = value;
			prev = next = NULL;
		}
	};

	Node* head;
	Node* tail;
public:

	DoublyLinkedList() {
		head = tail = NULL;
	}

	bool isEmpty() {
		return head == NULL;
	}

	void addLast(int value) {
		Node* newNode = new Node(value);
		if (isEmpty()) {
			head = tail = newNode;
			return;
		}
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}

	void printForward() {
		Node* curr = head;
		while (curr != NULL) {
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << "\n";
	}

	void printReverse() {
		Node* curr = tail;
		while (curr != NULL) {
			cout << curr->data << " ";
			curr = curr->prev;
		}
		cout << "\n";
	}
};


int main() {
	DoublyLinkedList nums = DoublyLinkedList();
	nums.addLast(10);
	nums.addLast(20);
	nums.addLast(30);
	nums.printForward();
	nums.printReverse();
	return 0;
}