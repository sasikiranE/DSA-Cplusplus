#include<bits/stdc++.h>

using namespace std;

class LinkedList {
private:

    class Node {
    public:
        int data;
        Node *next;

        Node(int value) {
            data = value;
            next = NULL;
        }

    };

    Node *head;
    Node *tail;
    int count;
public:

    LinkedList() {
        head = tail = NULL;
        count = 0;
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void addLast(int value) {
        Node *newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    void addFirst(int value) {
        Node *newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        count++;
    }

    void removeFirst() {
        if (isEmpty()) {
            throw underflow_error("list is already empty! cannot perform remove operation!");
        } else if (head == tail) {
            Node *temp = head;
            head = tail = NULL;
            delete temp;
        } else {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        count--;
    }

    void removeLast() {
        if (isEmpty()) {
            throw underflow_error("list is already empty! cannot perform remove operation!");
        } else if (head == tail) {
            Node *temp = head;
            head = tail = NULL;
            delete temp;
        } else {
            Node *curr = head;
            while (curr->next != tail) {
                curr = curr->next;
            }
            Node *temp = tail;
            curr->next = NULL;
            tail = curr;
            delete temp;
        }
        count--;
    }

    void removeNodeAt(int position) {
        if (position < 0 or position > size() - 1) {
            throw invalid_argument("invalid value for position!.");
        }
        if (position == 0) {
            removeFirst();
            return;
        }
        if (position == size() - 1) {
            removeLast();
            return;
        }
        int k = position - 1;
        Node *prev = head;
        while (k--) {
            prev = prev->next;
        }
        Node *curr = prev->next;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }

    int indexOf(int target) {
        Node *curr = head;
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
        Node *curr = head;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << "\n";
    }

    void reverse() {
        if (head == tail) {
            return;
        }
        Node *curr = head->next;
        Node *prev = head;
        while (curr != NULL) {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        tail = head;
        tail->next = NULL;
        head = prev;
    }

    int getKthFromEnd(int k) {
        if (k <= 0 or k > count) {
            return INT_MAX;
        }
        Node *a = head;
        Node *b = head;
        // move 'b' to (k - 1) distance apart from 'a'.
        for (int i = 0; i < k - 1; i++) {
            b = b->next;
        }
        // move 'a' and 'b' simultaneously until 'b' reaches the end.
        while (b != tail) {
            a = a->next;
            b = b->next;
        }
        // return value at 'a'
        return a->data;
    }
};


int main() {
    LinkedList nums = LinkedList();
    return 0;
}