#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    int size;
    vector<long long> items;
public:
    SegmentTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        items.assign(2 * size, 0LL);
    }

    SegmentTree(vector<int> &arr) {
        int n = arr.size();
        size = 1;
        while (size < n) size *= 2;
        items.assign(2 * size, 0LL);
        for (int i = 0; i < n; i++) {
            items[i + size] = arr[i];
        }
        for (int i = size - 1; i >= 1; i--) {
            items[i] = merge(items[2 * i] , items[2 * i + 1]);
        }
    }

    void update(int idx, int val) {
        update(idx, val, 1, 0, size - 1);
    }

    long long solve(int a, int b) {
        return solve(a, b, 1, 0, size - 1);
    }
private:
    long long merge(long long x, long long y) {
        return x + y;
    }

    void update(int idx, int val, int node, int left, int right) {
        if (left == right) {
            items[node] = val;
            return;
        }
        int mid = left + (right - left) / 2;
        if (idx >= left && idx <= mid) update(idx, val, 2 * node, left, mid);
        else update(idx, val, 2 * node + 1, mid + 1, right);
        items[node] = merge(items[2 * node], items[2 * node + 1]);
    }

    long long solve(int a, int b, int node, int left, int right) {
        if (left > b || right < a) return 0;
        if (left >= a && right <= b) return items[node];
        int mid = left + (right - left) / 2;
        long long s1 = solve(a, b, 2 * node, left, mid);
        long long s2 = solve(a, b, 2 * node + 1, mid + 1, right);
        return merge(s1, s2);
    }
};


int main() {
	return 0;
}