#include <iostream>
using namespace std;
class Person
{
public:
    string name;
    int age;
};
class Student : public Person
{
public:
    int rollno;
};
class Teacher : public Person
{
public:
    string subject;
};