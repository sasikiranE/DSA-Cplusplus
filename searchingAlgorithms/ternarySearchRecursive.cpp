#include<bits/stdc++.h>
using namespace std;


int ternarySearch(vector<int> &arr, int target, int low, int high) {
	if (low > high) return -1;

	int partitionSize = (high - low) / 3;
	int mid1 = low + partitionSize;
	int mid2 = high - partitionSize;

	if (arr[mid1] == target) return mid1;
	if (arr[mid2] == target) return mid2;
	if (target < arr[mid1]) {
		// it is in left partition.
		return ternarySearch(arr, target, low, mid1 - 1);
	}
	if (target > arr[mid2]) {
		// it is in right partition.
		return ternarySearch(arr, target, mid2 + 1, high);
	}
	else {
		// it is in middle partition.
		return ternarySearch(arr, target, mid1 + 1, mid2 - 1);
	}
}


int main() {
	// sorted array.
	vector<int> vals = {3, 4, 8, 9, 10};
	int n;
	cin >> n;
	cout << ternarySearch(vals, n, 0, vals.size() - 1) << "\n";
	return 0;
}