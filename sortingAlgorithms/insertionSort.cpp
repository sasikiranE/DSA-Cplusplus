#include<bits/stdc++.h>

using namespace std;


void insertionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int curr = arr[i];
        int j = i - 1;
        while (j >= 0 and curr < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = curr;
    }
}


int main() {
    vector<int> v = {9, 8, 3, 3, 2, -1, 6, 5, 3, 4, 2};
    insertionSort(v);
    for (auto &e: v) {
        cout << e << " ";
    }
    cout << "\n";
    return 0;
}
