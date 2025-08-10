#include<iostream>
using namespace std;
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
int getPascalTriangleElement(int row, int col){
    return ncr(row-1, col-1);
}

int main()
{
    int row, col;
    cout << "Enter the row and column for Pascal's Triangle: ";
    cin >> row >> col;
    cout << "Element at (" << row << ", " << col << ") is: "
         << getPascalTriangleElement(row, col) << endl;
    return 0;
}
