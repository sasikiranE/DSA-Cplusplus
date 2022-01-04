#include<bits/stdc++.h>

using namespace std;

class Queue {
    stack<int> stack1, stack2;
public:
    void enqueue(int value) {
        stack1.push(value);
    }

    bool isEmpty() {
        return stack1.empty() and stack2.empty();
    }

    int dequeue() {
        if (isEmpty()) {
            throw underflow_error("Queue is empty!. invalid operation dequeue");
        }
        if (stack2.empty()) {
            moveStack1ToStack2();
        }
        int front = stack2.top();
        stack2.pop();
        return front;
    }

    int peek() {
        if (isEmpty()) {
            throw underflow_error("Queue is empty!. invalid operation dequeue");
        }
        if (stack2.empty()) {
            moveStack1ToStack2();
        }
        return stack2.top();
    }

private:
    void moveStack1ToStack2() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
};


int main() {
    Queue q = Queue();
    return 0;
}