class MyLinkedList {
private:
    class Node {
    public:
        int val;
        Node* next;

        Node(int data) {
            val = data;
            next = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int size;

public:
    MyLinkedList() {
        head = tail = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if (index >= size) return -1;
        Node* curr = head;
        for (int i = 0; i < index; i++) {
            curr =  curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        size++;
        if (head == nullptr) {  
            head = tail = new Node(val);
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    
    void addAtTail(int val) {
        size++;
        if (head == nullptr) {
            head = tail = new Node(val);
            return;
        }
        Node* newNode = new Node(val);
        tail->next = newNode;
        tail = newNode;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index == size) {
            addAtTail(val);
            return;
        }
        if (index == 0) {
            addAtHead(val);
            return;
        }
        // add before (index) th node.
        Node* curr = head;
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }
        Node* newNode = new Node(val);
        newNode->next = curr->next;
        curr->next = newNode;
        size++;
    }

    void deleteAtHead() {
        if (head == nullptr) return;
        size--;
        if (head == tail) {
            head = tail = nullptr;
            return;
        }
        head = head->next;
    }

    void deleteAtTail() {
        if (head == nullptr) return;
        size--;
        if (head == tail) {
            head = tail = nullptr;
            return;
        }
        Node* curr = head;
        while (curr->next != tail) {
            curr = curr->next;
        }
        curr->next = nullptr;
        tail = curr;
    }
    
    void deleteAtIndex(int index) {
        if (index >= size) return;
        if (index == 0) {
            deleteAtHead();
            return;
        }
        if (index == size - 1) {
            deleteAtTail();
            return;
        }
        Node* prev = head;
        Node* curr = head->next;
        for (int i = 0; i < index - 1; i++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */