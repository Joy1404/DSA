#include <bits/stdc++.h>
using namespace std;

void buildTree(int i, int l, int r, vector<long long>& arr, vector<long long>& segment) {
    if (l == r) {
        segment[i] = arr[l];
        return;
    }

    int mid = (l + r) / 2;

    buildTree(2 * i + 1, l, mid, arr, segment);
    buildTree(2 * i + 2, mid + 1, r, arr, segment);

    segment[i] = segment[2 * i + 1] + segment[2 * i + 2];
}

void update(int i, int l, int r, int start, int end,
            long long value, vector<long long>& segment,
            vector<long long>& lazy) {

                if (lazy[i] != 0) {
                    segment[i] += (r - l + 1) * lazy[i];
            
                    if (l != r) {
                        lazy[2 * i + 1] += lazy[i];
                        lazy[2 * i + 2] += lazy[i];
                    }
            
                    lazy[i] = 0;
                }
                // out of range
    if (l > end || r < start) {
        return;
    }

    // in range
    if (start <= l && r <= end) {
        segment[i] += (r - l + 1) * value;

        if (l != r) {
            lazy[2 * i + 1] += value;
            lazy[2 * i + 2] += value;
        }

        return;
    }
   // overlapping
    int mid = (l + r) / 2;

    update(2 * i + 1, l, mid, start, end, value, segment, lazy);
    update(2 * i + 2, mid + 1, r, start, end, value, segment, lazy);

    segment[i] = segment[2 * i + 1] + segment[2 * i + 2];
}

long long rangeQuery(int i, int l, int r, int start, int end,
                     vector<long long>& segment,
                     vector<long long>& lazy) {

    if (end < l || start > r) {
        return 0;
    }

    if (lazy[i] != 0) {
        segment[i] += (r - l + 1) * lazy[i];

        if (l != r) {
            lazy[2 * i + 1] += lazy[i];
            lazy[2 * i + 2] += lazy[i];
        }

        lazy[i] = 0;
    }

    if (start <= l && r <= end) {
        return segment[i];
    }

    int mid = (l + r) / 2;

    return rangeQuery(2 * i + 1, l, mid, start, end, segment, lazy)
         + rangeQuery(2 * i + 2, mid + 1, r, start, end, segment, lazy);
}

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n);
    vector<long long> segment(4 * n);
    vector<long long> lazy(4 * n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    buildTree(0, 0, n - 1, arr, segment);

    for (int i = 0; i < 4 * n; i++) {
        cout << segment[i] << " ";
    }
    cout << endl;

    update(0, 0, n - 1, 1, 3, 2, segment, lazy);

    cout << rangeQuery(0, 0, n - 1, 2, 3, segment, lazy) << endl;

    return 0;
}