#include<iostream>
#include<vector>
using namespace std;
// Function to calculate nCr
int ncr(int n, int r)
{
   long long res = 1;
   for (int i = 0; i < r; i++)
   {
       res = res * (n - i);
       res = res / (i + 1);
   }
   return res;
}
// Function to generate Pascal's Triangle
//brute force
//time complexity: O(n^3)
//space complexity: O(n^2)
vector<vector<int>> generatepascaltriangle(int n){
    vector<vector<int>>ans(n);
    for(int row=1;row<=n;row++){
    vector<int>temp;
    for(int col=1;col<=row;col++){
        temp.push_back(ncr(row-1,col-1));
    }
    ans.push_back(temp);
}
    return ans;

}
//better solution
//time complexity: O(n^2)
//space complexity: O(n)
// it generates the ith row of Pascal's Triangle
vector<int>generaterow(int row){
    long long ans=1;
    vector<int>ansrow;
    ansrow.push_back(1);
    for(int col=1;col<row;col++){
        ans=ans*(row-col)/col;
        ansrow.push_back(ans);
    }
    return ansrow;
}
//it generates the Pascal's Triangle
vector<vector<int>> generatepascaltrianglebetter(int n){
    vector<vector<int>>ans;
    for(int row=1;row<=n;row++){
        ans.push_back(generaterow(row));
    }
    return ans;
}

//optimal
//time complexity: O(n^2)
//space complexity: O(n)
// it is solved by using the properties of Pascal's Triangle
// each element is the sum of the two elements above it
// the first and last elements are always 1
// the elements in between are calculated using the formula
// C(n, k) = C(n-1, k-1) + C(n-1, k)
vector<vector<int>> generatepascaltriangleoptimal(int numRows) {
        vector<vector<int>>triangle(numRows);
        for(int i=0;i<numRows;i++){
            triangle[i].resize(i+1);
            triangle[i][0]=triangle[i][i]=1;
        for(int j=1;j<i;j++){
            triangle[i][j]=triangle[i-1][j-1]+triangle[i-1][j];

        }
        }
        return triangle;
        
    }

int main()
{
    int n;
    cout << "Enter the number of rows for Pascal's Triangle: ";
    cin >> n;
    vector<vector<int>> pascalTriangle = generatepascaltriangleoptimal(n);
    for (const auto& row : pascalTriangle) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
