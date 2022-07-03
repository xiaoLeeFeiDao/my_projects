/*
 * @Description: 加号运算符重载
 * @Author: stone
 * @Date: 2020-02-12 13:28:10
 * @LastEditTime : 2020-02-13 10:00:47
 * @LastEditors  : stone
 */
#include "test.h"
#include <iostream>
#include <string>
using namespace std;

class Student {
    friend Student operator+(const Student& stu1, const Student& stu2);
    friend ostream& operator<<(ostream& cout, Student& stu);

public:
    Student();
    Student(string name, int age, int record);
    Student(const Student& stu);
    Student& getInfo();
    Student addObjCustom(const Student& stu);
    Student operator+(const Student& stu);
    void display();
    ~Student();

private:
    int m_Age;
    string m_Name;
    int m_Record;
};
Student::Student()
{
    m_Age = 0;
    m_Record = 0;
    m_Name = "";
}
Student::Student(string name, int age, int record)
{
    m_Age = age;
    m_Record = record;
    m_Name = name;
}
Student::Student(const Student& stu)
{
    m_Age = stu.m_Age;
    m_Record = stu.m_Record;
    m_Name = stu.m_Name;
}
void Student::display()
{
    cout << "name = " << this->m_Name << endl;
    cout << "age = " << this->m_Age << endl;
    cout << "record = " << this->m_Record << endl;
}
Student& Student::getInfo()
{
    return *this;
}
Student::~Student()
{
}
////自定义两个类相加
Student Student::addObjCustom(const Student& stu)
{
    Student tmp;
    tmp.m_Age = this->m_Age + stu.m_Age;
    tmp.m_Record = this->m_Record + stu.m_Record;
    tmp.m_Name = this->m_Name + stu.m_Name;
    return tmp;
}
////编译器给起了一个名字
Student Student::operator+(const Student& stu)
{
    Student tmp;
    tmp.m_Age = this->m_Age + stu.m_Age;
    tmp.m_Record = this->m_Record + stu.m_Record;
    tmp.m_Name = this->m_Name + stu.m_Name;
    return tmp;
}
////全局函数的符号重载
Student operator+(const Student& stu1, const Student& stu2)
{
    Student tmp;
    tmp.m_Age = stu1.m_Age + stu2.m_Age;
    tmp.m_Record = stu1.m_Record + stu2.m_Record;
    tmp.m_Name = stu1.m_Name + stu2.m_Name;
    return tmp;
}
ostream& operator<<(ostream& cout, Student& stu)
{
    cout << "m_Name = " << stu.m_Name << " m_Age = " << stu.m_Age << " m_Record = " << stu.m_Record;
    return cout;
}
/**
 * @description: 
 * @param : 
 * @return: 
 */
void test32()
{
    Student stu0;
    Student stu1("stone", 18, 100);
    Student stu2 = stu0.addObjCustom(stu1);
    Student stu3 = stu1.addObjCustom(stu2);
    stu3.display();

    Student stu4 = stu3.operator+(stu2);
    stu4.display();
    //简化为
    Student stu5 = stu4 + stu0;
    stu5.display();

    ////全局函数重载
    Student stu6 = operator+(stu5, stu4);
    stu6.display();
    ////简化为
    Student stu7 = stu6 + stu5;
    stu7.display();

    ////左移运算符重载
    cout << stu7 << endl;
    return;
}