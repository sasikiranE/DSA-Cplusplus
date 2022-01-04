#include<bits/stdc++.h>

using namespace std;


struct segementTree {
    int size;
    vector<long long> tree;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, 0);
    }

    void build(vector<int> &v) {
        init(v.size());
        for (int i = 0; i < v.size(); i++) {
            tree[i + size] = v[i];
        }
        for (int i = size - 1; i >= 1; i--) {
            tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
        }

    }

    long long merge(long long x, long long y) {
        return x + y;
    }

    void set(int i, int v) {
        i += size;
        tree[i] = v;
        for (int j = i / 2; j >= 1; j /= 2) {
            tree[j] = merge(tree[2 * j], tree[2 * j + 1]);
        }
    }

    long long solve(int a, int b) {
        a += size;
        b += size;
        long long ans = 0;
        while (a <= b) {
            if (a % 2 == 1) ans = merge(tree[a++], ans);
            if (b % 2 == 0) ans = merge(tree[b--], ans);
            a /= 2;
            b /= 2;
        }
        return ans;
    }
};


int main() {
    return 0;
}
