#include<bits/stdc++.h>
using namespace std;

void reverseQueue(queue<int> &q) {
	stack<int> st;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		st.push(x);
	}
	while (!st.empty()) {
		int x = st.top();
		st.pop();
		q.push(x);
	}
}

void printQueue(queue<int> q) {
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

int main() {
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	printQueue(q);
	reverseQueue(q);
	printQueue(q);
	return 0;
}