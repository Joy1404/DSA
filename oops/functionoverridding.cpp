#include<iostream>
using namespace std;
class Parent{
    public:
    void getinfo(){
        cout<<"Parent class";
    }
   virtual void hello(){
        cout<<" hello from Parent class";
    }
    
};
//function overloading
class Child:public Parent{
    public:
    void getinfo(){
        cout<<"child class";
    }
    void hello(){
        cout<<"hello from child class";
    }
};

int main(){
    Child c1;
    c1.hello();
return 0;
}