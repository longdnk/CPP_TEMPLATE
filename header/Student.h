//
// Created by longsiga on 12/3/22.
//

#ifndef CPP_TEST_STUDENT_H
#define CPP_TEST_STUDENT_H

#include <string>
#include <vector>

using namespace std;

class Student {
private:
    string name;
    double math {};
    double physic {};
    double chemistry {};
public:
    Student();

    Student(const string &name, double math, double physic, double chemistry);

    const string &getName() const;

    void setName(const string &name);

    double getMath() const;

    void setMath(double math);

    double getPhysic() const;

    void setPhysic(double physic);

    double getChemistry() const;

    void setChemistry(double chemistry);

    double avgPoint() const;

    void display();

    static vector<Student> getStudentMaxAvg(vector<Student> vt);

    static vector<Student> getStudentMaxMath(vector<Student> vt);

    static vector<Student> getStudentMaxPhysic(vector<Student> vt);

    static vector<Student> getStudentMaxChemistry(vector<Student> vt);
};

#endif //CPP_TEST_STUDENT_H
