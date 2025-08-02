#include <iostream>
using namespace std;

class Person{
public:
string name;
int age;

Person(string name,int age){
    this->name=name;
    this->age=age;
}
// Person(){
//   cout<<"parent constructor..\n";
// }
// ~Person(){
//     cout<<"parent desstructor..\n";
// }

};
class Student:public Person{
public:
int rollno;
// Student(){
//     cout<<"student constructor..\n"; for default constructor
// }
Student(string name,int age,int rollno):Person( name,age){
    this->rollno=rollno;
}
// ~Student(){
//     cout<<"student desstructor..\n";
// }
void getinfo(){
    cout<<"name:"<<name<<endl;
    cout<<"age:"<<age<<endl;
    cout<<"rollno:"<<rollno<<endl;
}
};
int main(){
    Student s1("rahul kumar",21,1234);
   
    s1.getinfo();
    return 0;
}