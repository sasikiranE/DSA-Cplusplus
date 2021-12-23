#include<bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> &arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

int main() {
    vector<int> vals = {3, 9, 10, 8, 4};
    cout << linearSearch(vals, 10) << "\n";
    return 0;
}