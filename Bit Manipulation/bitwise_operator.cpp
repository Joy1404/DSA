#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a=5,b=6;
    // 5=0101, 6=0110 in or if one bit is 1 then 1 else 0 and result is always greater than or equal to the maximum of a and b
    cout<<(a|b)<<endl; // bitwise OR
    // 5=0101, 6=0110 in and if both are 1 then 1 else 0 and result is always less than or equal to the minimum of a and b
    cout<<(a&b)<<endl; // bitwise AND
    // 5=0101, 6=0110 in xor if both are different then 1 else 0(even 1s are 0 and odd 1s are 1) and result is always less than or equal to the maximum of a and b
    cout<<(a^b)<<endl; // bitwise XOR
    // ~x = -(x+1) 5=0101, ~5=1010=-6
    cout<<(~a)<<endl;  // bitwise NOT
    // a<<x means shifting the bits of a to the left by x positions and filling the rightmost x bits with 0. This is equivalent to multiplying a by 2^x.
    // a>>x means shifting the bits of a to the right by x positions and filling the leftmost x bits with 0 (for unsigned types) or with the sign bit (for signed types). This is equivalent to dividing a by 2^x.
    cout<<(a<<1)<<endl; // left shift
    cout<<(a>>1)<<endl; // right shift
    return 0;
}