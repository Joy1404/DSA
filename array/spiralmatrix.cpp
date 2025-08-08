#include<iostream>
#include<vector>
using namespace std;

// Function to generate a spiral matrix
// time complexity: O(n*m)
// space complexity: O(n*m)
vector<vector<int>> generateSpiralMatrix(int n,int m) {
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    int left = 0, right = m - 1, top = 0, bottom = n - 1;
    int num = 1;

    while (left <= right && top <= bottom) {
        // Fill top row
        for (int i = left; i <= right; i++) {
            matrix[top][i] = num++;
        }
        top++;

        // Fill right column
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = num++;
        }
        right--;

        // Fill bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = num++;
            }
            bottom--;
        }

        // Fill left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = num++;
            }
            left++;
        }
    }

    return matrix;
}
vector<int> traverseSpiralMatrix(const vector<vector<int>>& matrix) {
    vector<int> result;
    if (matrix.empty() || matrix[0].empty()) return result;

    int left = 0, right = matrix[0].size() - 1;
    int top = 0, bottom = matrix.size() - 1;

    while (left <= right && top <= bottom) {
        // Traverse top row
        for (int i = left; i <= right; i++) {
            result.push_back(matrix[top][i]);
        }
        top++;

        // Traverse right column
        for (int i = top; i <= bottom; i++) {
            result.push_back(matrix[i][right]);
        }
        right--;

        // Traverse bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // Traverse left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;

    int m;
    cout << "Enter the number of columns: ";
    cin >> m;

    vector<vector<int>> spiralMatrix = generateSpiralMatrix(n,m);
    vector<int> spiralTraversal = traverseSpiralMatrix(spiralMatrix);

    cout << "Spiral Matrix:" << endl;
    for (const auto& row : spiralMatrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    cout << "Spiral Traversal:" << endl;
    for (int val : spiralTraversal) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}