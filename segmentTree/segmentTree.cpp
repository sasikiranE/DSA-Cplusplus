#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    /*
        set(idx, val) => sets the value at index idx to val;
        sum(l, r) => return sum from index = l to index = r - 1;
    */
    int size;
    vector<long long> items;
public:
    SegmentTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        items.assign(2 * size, 0LL);
    }

    SegmentTree(vector<int> &arr) {
        size = 1;
        int n = arr.size();
        while (size < n) size *= 2;
        items.assign(2 * size, 0LL);
        build(arr, 0, 0, size);
    }

    void set(int idx, int val) {
        set(idx, val, 0, 0, size);
    }

    long long sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
private:
    void build(vector<int> &arr, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < arr.size()) items[x] = arr[lx];
            return;
        }
        int mid = lx + (rx - lx) / 2;
        build(arr, 2 * x + 1, lx, mid);
        build(arr, 2 * x + 2, mid, rx);
        items[x] = items[2 * x + 1] + items[2 * x + 2];
    }

    void set(int idx, int val, int x, int lx, int rx) {
        if (rx - lx == 1) {
            items[x] = val;
            return;
        }
        int mid = lx + (rx - lx) / 2;
        if (idx < mid) set(idx, val, 2 * x + 1, lx, mid);
        else set(idx, val, 2 * x + 2, mid, rx);
        items[x] = items[2 * x + 1] + items[2 * x + 2];
    }

    long long sum(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return 0;
        if (lx >= l && rx <= r) return items[x];
        int mid = lx + (rx - lx) / 2;
        long long s1 = sum(l, r, 2 * x + 1, lx, mid);
        long long s2 = sum(l, r, 2 * x + 2, mid, rx);
        return s1 + s2;
    }
};


int main() {
	return 0;
}