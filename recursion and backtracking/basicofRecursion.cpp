#include<iostream>
using namespace std;
// void f(){ //this recursion will run infinitely because ut has no stooping condition
//     cout<<1<<endl;
//     f();
// }
int count=0;
void f(){
    if(count==4) return; //it is base condition for stopping recursion
    cout<<count;
    count++;
    f();
}
int main(){
    f();
    return 0;
}