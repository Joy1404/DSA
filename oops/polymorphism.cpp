#include<iostream>
using namespace std;
class Student{
    public:
    string name;
    Student(){
        cout<<"not parametrised\n";
    }
    Student(string name){
        cout<<" parametrised\n";
    }
};
//function overloading
class Print{
    public:
    void show(int x){
        cout<<"int x:"<<x<<endl;
    }
    void show(char ch){
        cout<<"char ch:"<<ch<<endl;
    }
};

int main(){
    // Student s1("j");
    Print p1;
    p1.show(101);
    return 0;
}