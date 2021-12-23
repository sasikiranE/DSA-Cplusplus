#include<bits/stdc++.h>
using namespace std;

class maxHeap {
    vector<int> items;
    int size;

public:
    maxHeap() {
        size = 0;
    }

    maxHeap(vector<int> &arr) {
        size = arr.size();
        for (int i = 0; i < size; i++) {
            items.push_back(arr[i]);
        }
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(i);
        }
    }

    void insert(int value) {
        items.push_back(value);
        size++;
        bubbleUp();
    }

    int top() {
        if (size == 0) return INT_MIN;
        return items[0];
    }

    void pop() {
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


void heapSort(vector<int> &arr) {
    int n = arr.size();
    maxHeap heap = maxHeap();
    for (int i = 0; i < n; i++) {
        heap.insert(arr[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = heap.top();
        heap.pop();
    }
}


int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90, 25, 32, 11};
    heapSort(arr);
    for (auto &e : arr) {
        cout << e << " ";
    }
    cout << "\n";
    return 0;
}