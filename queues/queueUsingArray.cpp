#include <bits/stdc++.h>
using namespace std;

// Queue implementation using Circular Array.

class Queue {
	int F, R, capacity;
	vector<int> items;
	int count;
public:
	Queue(unsigned int size) {
		capacity = size;
		items.assign(capacity, 0);
		F = R = 0;
		count = 0;
	}

	bool isEmpty() {
		return count == 0;
	}

	bool isFull() {
		return count == capacity;
	}

	void enqueue(int value) {
		if (isFull()) {
			throw overflow_error("queue is full! cannot enqueue items.");
			return;
		}
		items[R] = value;
		R = (R + 1) % capacity;
		count++;
	}

	int front() {
		if (isEmpty()) {
			throw underflow_error("queue is empty! cannot do dequeue operation.");
		}
		return items[F];
	}

	int dequeue() {
		if (isEmpty()) {
			throw underflow_error("queue is empty! cannot do dequeue operation.");
		}
		int data = items[F];
		items[F] = 0;
		F = (F + 1) % capacity;
		count--;
		return data;
	}

	void print() {
		for (auto &e : items) {
			cout << e << " ";
		}
		cout << endl;
	}
};


int main() {
	return 0;
}