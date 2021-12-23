#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int target) {
	int low = 0;
	int high = arr.size() - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (target < arr[mid]) high = mid - 1;
		else if (target > arr[mid]) low = mid + 1;
		else return mid;
	}

	return -1;
}

int main() {
    // sorted array.
    vector<int> vals = {3, 4, 8, 9, 10};
    int n;
    cin >> n;
    cout << binarySearch(vals, n) << "\n";
    return 0;
}