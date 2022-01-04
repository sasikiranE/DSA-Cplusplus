#include <bits/stdc++.h>

using namespace std;

void coutingSort(vector<int> &arr) {
    int maximum = -1;
    for (int e: arr) {
        maximum = max(maximum, e);
    }
    vector<int> counts(maximum + 1, 0);
    for (int e: arr) {
        counts[e]++;
    }
    int j = 0;
    for (int i = 0; i < counts.size(); i++) {
        int k = counts[i];
        while (k--) {
            arr[j++] = i;
        }
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90, 25, 32, 11, 0};
    coutingSort(arr);
    for (auto &e: arr) {
        cout << e << " ";
    }
    cout << "\n";
    return 0;
}