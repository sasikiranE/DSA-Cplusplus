#include<bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &arr, int target, int low, int high) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (target < arr[mid]) return binarySearch(arr, target, low, mid - 1);
    else if (target > arr[mid]) return binarySearch(arr, target, mid + 1, high);
    else return mid;
}

int main() {
    // sorted array.
    vector<int> vals = {3, 4, 8, 9, 10};
    cout << binarySearch(vals, 8, 0, vals.size() - 1) << "\n";
    return 0;
}