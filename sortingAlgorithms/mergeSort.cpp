#include<bits/stdc++.h>

using namespace std;

void merge(vector<int> &left, vector<int> &right, vector<int> &arr) {
    int i = 0, j = 0, k = 0;
    while (i < left.size() and j < right.size()) {
        if (left[i] <= right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }
    while (i < left.size()) {
        arr[k++] = left[i++];
    }
    while (j < right.size()) {
        arr[k++] = right[j++];
    }
}

void mergeSort(vector<int> &arr) {
    if (arr.size() <= 1) {
        return;
    }
    // divide into half.
    int mid = arr.size() / 2;
    vector<int> left(mid);
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    vector<int> right(arr.size() - mid);
    for (int i = mid; i < arr.size(); i++) {
        right[i - mid] = arr[i];
    }
    // sort the halfs.
    mergeSort(left);
    mergeSort(right);
    // Merge two halfs.
    merge(left, right, arr);
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90, 25, 32, 11, -3, 0};
    mergeSort(arr);
    for (auto &e: arr) {
        cout << e << " ";
    }
    cout << "\n";
    return 0;
}