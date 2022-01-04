#include<bits/stdc++.h>

using namespace std;

class Stack {
private:

    int capacity;
    vector<int> items;
    int top;
public:

    Stack() {
        capacity = 1e5;
        top = -1;
        items.assign(capacity, 0);
    }

    Stack(int size) {
        capacity = size;
        top = -1;
        items.assign(capacity, 0);
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int value) {
        if (top == capacity - 1) {
            throw overflow_error("Stack Overflow!. stack is full.");
        }
        items[++top] = value;
    }

    int peek() {
        if (top == -1) {
            throw underflow_error("Stack Underflow!. stack is empty.");
        }
        return items[top];
    }

    void pop() {
        if (top == -1) {
            throw underflow_error("Stack Underflow!. stack is empty.");
        }
        top--;
    }
};


int main() {
    Stack st = Stack();
    return 0;
}