#include<iostream>
using namespace std;
class Student{
    public:
    string name;
    int rollno;
};
class Teacher{
public:
string subject;
int salary;
};
class TA: public Student,public Teacher{
};
int main(){
    TA t1;
    t1.name="tony stark";
    t1.subject="engineeering";
   
    cout<<t1.name<<"\n";
    cout<<t1.subject<<"\n";
    return 0;
}