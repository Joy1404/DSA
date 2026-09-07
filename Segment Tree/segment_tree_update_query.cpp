#include <bits/stdc++.h>
using namespace std;

void buildTree(int i, int l, int r,
               vector<int>& arr, vector<int>& segment) {

    if (l == r) {
        segment[i] = arr[l];
        return;
    }

    int mid = (l + r) / 2;

    buildTree(2 * i + 1, l, mid, arr, segment);
    buildTree(2 * i + 2, mid + 1, r, arr, segment);

    segment[i] = segment[2 * i + 1] + segment[2 * i + 2];
}

void update(int i, int l, int r, int idx, int val,
            vector<int>& arr, vector<int>& segment) {

    if (l == r) {
        arr[idx] = val;
        segment[i] = val;
        return;
    }

    int mid = (l + r) / 2;

    if (idx <= mid) {
        update(2 * i + 1, l, mid, idx, val, arr, segment);
    }
    else {
        update(2 * i + 2, mid + 1, r, idx, val, arr, segment);
    }

    segment[i] = segment[2 * i + 1] + segment[2 * i + 2];
}

int main() {

    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    vector<int> segment(4 * n);

    cout << "Enter the array elements: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    buildTree(0, 0, n - 1, arr, segment);

    cout << "Segment tree before update:\n";

    for (int i = 0; i < 4 * n; i++) {
        cout << segment[i] << " ";
    }

    int idx, val;

    cout << "\nEnter index and new value: ";
    cin >> idx >> val;

    update(0, 0, n - 1, idx, val, arr, segment);

    cout << "Segment tree after update:\n";

    for (int i = 0; i < 4 * n; i++) {
        cout << segment[i] << " ";
    }

    return 0;
}