#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int start, int end) {
    // select last element as pivot.
    int pivot = arr[end];
    int boundary = start - 1;
    for (int i = start; i <= end ; i++) {
        if (arr[i] <= pivot) {
            swap(arr[i], arr[++boundary]);
        }
    }
    return boundary;
}

void quickSort(vector<int> &arr, int start, int end) {
    if (start >= end) return;
    int boundary = partition(arr, start, end);
    quickSort(arr, start, boundary - 1);
    quickSort(arr, boundary + 1, end);
}

void QuickSort(vector<int> &arr) {
    quickSort(arr, 0, arr.size() - 1);
}


int main() {
    vector<int> arr = {};
    QuickSort(arr);
    for (auto &e : arr) {
        cout << e << " ";
    }
    cout << "\n";
    return 0;
}