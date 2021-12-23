#include<bits/stdc++.h>
using namespace std;


int ternarySearch(vector<int> &arr, int target) {
	int low = 0;
	int high = arr.size() - 1;

	while (low <= high) {
		int partitionSize = (high - low) / 3;
		int mid1 = low + partitionSize;
		int mid2 = high - partitionSize;
		
		if (arr[mid1] == target) return mid1;
		if (arr[mid2] == target) return mid2;

		if (target < arr[mid1]) high = mid1 - 1;
		else if (target > arr[mid2]) low = mid2 + 1;
		else {
			low = mid1 + 1;
			high = mid2 - 1;
		}
	}

	return -1;
}


int main() {
	// sorted array.
	vector<int> vals = {3, 4, 8, 9, 10};
	int n;
	cin >> n;
	cout << ternarySearch(vals, n) << "\n";
	return 0;
}