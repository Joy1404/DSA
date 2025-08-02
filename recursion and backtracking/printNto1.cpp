#include <iostream>
using namespace std;
// void f(int i)
// {
//     if (i ==0)
//         return;
//     cout << i<<" ";
//     f(i - 1);
// }
// int main()
// {
//     int n;
//     cin >> n;
//     f(n);
//     return 0;
// }
void f(int i,int n)
{
    if (i ==0)
        return;
    cout << i<<" ";
    f(i - 1,n);
}
int main()  
{
    int n;
    cin >> n;
    f(n,n);
    return 0;
}