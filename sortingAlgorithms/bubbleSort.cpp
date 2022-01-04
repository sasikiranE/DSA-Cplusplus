#include<bits/stdc++.h>

using namespace std;


void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        bool isSorted = true;
        for (int j = 1; j < n - i; j++) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
                isSorted = false;
            }
        }
        if (isSorted) break;
    }
}


int main() {
    vector<int> v = {9, 8, 3, 3, 2, -1, 6, 5, 3, 4, 2};
    bubbleSort(v);
    for (auto &e: v) {
        cout << e << " ";
    }
    cout << "\n";
    return 0;
}