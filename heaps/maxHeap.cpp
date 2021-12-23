#include<bits/stdc++.h>
using namespace std;

class maxHeap {
    vector<int> items;
    int size;

public:
    maxHeap() {
        size = 0;
    }

    void insert(int value) {
        items.push_back(value);
        size++;
        bubbleUp();
    }

    void remove() {
        if (size == 0) {
            return;
        }
        items[0] = items[size - 1];
        size--;
        int index = 0;
        heapify(index);
    }

private:
    int parent(int x) {
        return (x - 1) / 2;
    }

    int left(int x) {
        return 2 * x + 1;
    }

    int right(int x) {
        return 2 * x + 2;
    }

    void bubbleUp() {
        int index = size - 1;
        while (index > 0 and items[index] > items[parent(index)]) {
            swap(items[index], items[parent(index)]);
            index = parent(index);
        }
    }

    void heapify(int idx) {
        int left_idx = left(idx);
        int right_idx = right(idx);
        int largestChildIndex = idx;
        if (left_idx < size and items[left_idx] > items[largestChildIndex])
            largestChildIndex = left_idx;
        if (right_idx < size and items[right_idx] > items[largestChildIndex])
            largestChildIndex = right_idx;
        if (largestChildIndex != idx) {
            swap(items[idx], items[largestChildIndex]);
            heapify(largestChildIndex);
        }
    }
};

int main() {
    maxHeap heap = maxHeap();
    return 0;
}