#include<bits/stdc++.h>

using namespace std;


void selectionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        swap(arr[i], arr[min_idx]);
    }
}


int main() {
    vector<int> v = {9, 8, 3, 3, 2, -1, 6, 5, 3, 4, 2};
    selectionSort(v);
    for (auto &e: v) {
        cout << e << " ";
    }
    cout << "\n";
    return 0;
}