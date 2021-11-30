#include <iostream>
using namespace std;

class Student
{
private:    
    string sName;
    string initials;
    
    int birthYear;
    int course;
    int passNumber;
    int groupNumber;

public:

    Studen()
    {
        sName = "none";
        initials = "none";
        birthYear = 0;
        course = 0;
        passNumber = 0;
        groupNumber = 0;
    }

    Student(string snm, string init, int byear, int c, int pn, int gn)
    {
        sName = snm;
        initials = init;
        birthYear = byear;
        course = c;
        passNumber = pn;
        groupNumber = gn;
    }



    // Setter
    void setsName(string sn) 
    {
        sName = sn;
    }

    // Getter
    string getsName()
    {
        return sName;
    }

public:
    // Setter
    void setinitials(string in)
    {
        initials = in;
    }

    // Getter
    string getinitials()
    {
        return initials;
    }



public:
    // Setter
    void setbirthYear(int by)
    {
        birthYear = by;
    }

    // Getter
    int getbirthYear()
    {
        return birthYear;
    }

public:
    // Setter
    void setcourse(int c)
    {
        course = c;
    }

    // Getter
    int getcourse()
    {
        return course;
    }

public:
    // Setter
    void setpassNumber(int pnumb)
    {
        passNumber = pnumb;
    }

    // Getter
    int getpassNumber()
    {
        return passNumber;
    }

public:
    // Setter
    void setgroupNumber(int gpN)
    {
        groupNumber = gpN;
    }

    // Getter
    int  getgroupNumber()
    {
        return groupNumber;
    }



};


int main(){

    Student obj;
    obj.setsName("Lazarenko ");
    obj.setinitials("M E");
    cout<< "Student name: " << obj.getsName() + obj.getinitials()<<endl;
    obj.setbirthYear(2003);
    cout<<"Student birthyear: " <<obj.getbirthYear()<<endl;
    obj.setcourse(2);
    cout<<"Student course: " <<obj.getcourse()<<endl;
    obj.setpassNumber(55789);
    cout<<"Student passNumbet: " <<obj.getpassNumber()<<endl;
    obj.setgroupNumber(6);
    cout<<"Student group number: "<<obj.getgroupNumber()<<endl;

    Student c("Lazarenko ", "M E ", 2003, 2, 532532, 6);
    string z = c.getsName();
    string p = c.getinitials();
    int m = c.getbirthYear();
    int l = c.getcourse();
    int f = c.getpassNumber();
    int o = c.getgroupNumber();
    cout<< o;
    return 0;

}





