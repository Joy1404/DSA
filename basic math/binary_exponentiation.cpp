#include <bits/stdc++.h>
using namespace std;
int M = 1e9 + 7;
long long binpower(long long base, long long exp)
{
    long long res = 1;
    base %= M;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            res = (res * base) % M;
        }
        base = (base * base) % M;
        exp /= 2;
    }
    return res;
}
long long findpower(int a, int b)
{
    if (b == 0)
        return 1;
    int half = findpower(a, b / 2);
    int result = (half * half);
    if (b % 2 == 1)
        result = result * a;
    return result;
}