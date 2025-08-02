#include<iostream>
using namespace std;
//  void fun(){
//     static int x=0;//init statement - 1run``    1   
//     cout<<x<<endl;
//     x++;
//  }
class A{
    public:
int x;
void inx(){
    x=x+1;
}
};
int main(){
    A obj1;
    A obj2;
    obj1.x=100;
    obj2.x=200;
    // fun();
    // fun();
    // fun();
    return 0;
}