#include <iostream>
using namespace std;

class Teacher
{
private:
    double salary;

public:
    // properties /attributes
    string name;
    string dept;
    string subject;
    // non-parameterised
    //  Teacher(){  //constructor
    //      dept="computer science";//initialise dept
    //  }
    // parameterised
    Teacher(string name, string dept, string subject, double salary)
    { // constructor
        //    name=n;
        //    subject=s;
        //    dept=d;
        //    salary=sal;
        this->name = name;
        this->dept = dept;
        this->subject = subject;
        this->salary = salary;
    }
    // cpoy constructor
    Teacher(Teacher &orgobj)
    { // pass by reference
        cout << "i am custom copy constuctor";
        this->name = orgobj.name;
        this->dept = orgobj.dept;
        this->subject = orgobj.subject;
        this->salary = orgobj.salary;
    }

    // methods/member function
    void changeDept(string newdept)
    {
        dept = newdept;
    }
    // setter
    void setsalary(double s)
    {
        salary = s;
    }
    // getter
    double getsalary()
    {
        return salary;
    }
    void getinfo()
    {
        cout << "name:" << name << endl;
        cout << "subject:" << subject << endl;
    }
};
int main()
{
    Teacher t1("joy", "computer science", "c++", 25000); // constructor call
    // Teacher t2;
    // t1.name="Joy";
    // t1.subject="c++";
    // t1.dept="computer science";
    t1.getinfo();
    Teacher t2(t1); // default copy constructor -invoke
    t2.getinfo();
    // t1.setsalary(25000);
    // cout<<t1.getsalary()<<endl;
}