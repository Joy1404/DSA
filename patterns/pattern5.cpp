#include <iostream>
// #include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int n;
    for (int i = 0; i < t; i++)
    {
        cout << "enter the number of rows:";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n-i; j++)
            // for (int j = 0; j <=n-i-1; j++) if i=1 then j<n-i+1
            {
                cout << "*";
            }
            cout << "\n";
        }
    }
    return 0;
}
