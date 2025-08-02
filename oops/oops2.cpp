#include<iostream>
using namespace std;
class Student{
    public:
    string name;
    // double cgpa;
    double *cgpaptr;
    Student(string name,double cgpa){
        this->name=name;
       cgpaptr = new double;
       *cgpaptr=cgpa;
    }
    // Student(Student &obj){
    //     this->name=obj.name;
    //     this->cgpa=obj.cgpa;
    // }
    // Student(Student &obj){
    //     this->name=obj.name;
    //     this->cgpaptr=obj.cgpaptr;
    // }
    // Student(Student &obj){
    //     this->name=obj.name;
    //     cgpaptr = new double;//deep copy
    //     *cgpaptr=*obj.cgpaptr;
    // }
    //destructor
    ~Student(){
        cout<<"hi,i delete everything";
        delete cgpaptr; //memory leak problem
    }

    void getinfo(){
      cout<<"name:"<<name<<endl;
      cout<<"cgpa:"<<*cgpaptr<<endl;
    }

};
int main(){
    Student s1("rahul kumar",8.9);
    s1.getinfo();
    // Student s2(s1);
    // *(s2.cgpaptr)=9.2;
    // s1.getinfo();//now cgpa will be 9.2 because of shallow copy but it will be solved by deep copy
    // s2.name="neha";
    // s2.getinfo();
    return 0;
}