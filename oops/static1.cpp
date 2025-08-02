#include<iostream>
using namespace std;
class A{
public:
  A(){
    cout<<"constructor\n";
  }
  ~A(){
    cout<<"destructor\n";
  }
};
int main(){
    if(true){
        static A obj;
    }
    cout<<"end of main function\n";
    return 0;
}