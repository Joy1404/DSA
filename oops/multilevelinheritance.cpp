#include<iostream>
using namespace std;
class Person{
    public:
    string name;
    int age;
};
class Student:public Person{
public:
int age;
};
class Gradstudent: public Student{
    public:
    string researchArea;

};
int main(){
    Gradstudent s1;
    s1.name="tony stark";
    s1.researchArea="quantam mechanics";
    cout<<s1.name<<"\n";
    cout<<s1.researchArea;
    return 0;
}