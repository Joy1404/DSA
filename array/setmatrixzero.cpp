#include<iostream>
#include<vector>
using namespace std;
// Function to set entire row and column to zero if an element is zero
//brute force code
void markrow(int i, vector<vector<int>>& matrix) {
    for(int j=0; j<matrix[0].size(); j++) {
       if( matrix[i][j] != 0){
        matrix[i][j]=-1; // Marking the row with -1 to avoid confusion with zero
       }
    }
}
void markcol(int j, vector<vector<int>>& matrix) {
    for(int i=0; i<matrix.size(); i++) {
        if(matrix[i][j] != 0) {
            matrix[i][j] = -1; // Marking the column with -1 to avoid confusion with zero
        }
    }
}
void setMatrixZeroBruteForce(vector<vector<int>>& matrix, int n, int m){
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(matrix[i][j] == 0) {
                markrow(i, matrix);
                markcol(j, matrix);
            }
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(matrix[i][j] == -1) {
                matrix[i][j] = 0; // Setting the marked elements to zero
            }
        }
    }
}
//better force code
// this code has O(n*m) time complexity and O(1) space complexity
// It iterates through the matrix and marks the rows and columns that need to be zeroed
void setMatrixZeroBetterForce(vector<vector<int>>& matrix, int n, int m)
{
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(matrix[i][j] == 0) {
                // Set entire row to zero
                for(int k=0;k<m;k++) {
                    matrix[i][k] = 0;
                }
                // Set entire column to zero
                for(int k=0;k<n;k++) {
                    matrix[k][j] = 0;
                }
            }
        }
    }
}
//optimal code
void setMatrixZero(vector<vector<int>>& matrix,int n,int m) {
    int col0=1; // To track if the first column needs to be zeroed
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0; // Set first element of the row to zero
                if(j != 0) {
                    matrix[0][j] = 0; // Set first element of the column to zero
                } else {
                    col0 = 0; // If the first column has a zero, mark it
                }
            }
        }
    }
    // Set the elements to zero based on the first row and column
    for(int i=1;i<n;i++) { 
        for(int j=1;j<m;j++) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0; // Set the element to zero
            }
        }
    }
    if(matrix[0][0] == 0) {
        for(int j=0;j<m;j++) {
            matrix[0][j] = 0; // Set the first row to zero
        }
    }
    if(col0 == 0) {
        for(int i=0;i<n;i++) {
            matrix[i][0] = 0; // Set the first column to zero
        }
    }
}
// Function to print the matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for(const auto& row : matrix) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// Main function to test the setMatrixZero function
int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    
    cout << "Original Matrix:" << endl;
    printMatrix(matrix);
    
    setMatrixZeroBruteForce(matrix, 3, 3);
    
    cout << "Matrix after setting zeros:" << endl;
    printMatrix(matrix);
    
    return 0;
}