//
// Created by longsiga on 12/3/22.
//

// all method here
#include <iostream>
#include "Student.h"

using namespace std;

Student::Student() = default;

Student::Student(const string &name, double math, double physic, double chemistry) : name(name), math(math), physic(physic), chemistry(chemistry) {
    this->name = name;
    this->math = math;
    this->physic = physic;
    this->chemistry = chemistry;
}

const string &Student::getName() const {
    return name;
}

void Student::setName(const string &name) {
    Student::name = name;
}

double Student::getMath() const {
    return math;
}

void Student::setMath(double math) {
    Student::math = math;
}

double Student::getPhysic() const {
    return physic;
}

void Student::setPhysic(double physic) {
    Student::physic = physic;
}

double Student::getChemistry() const {
    return chemistry;
}

void Student::setChemistry(double chemistry) {
    Student::chemistry = chemistry;
}

double Student::avgPoint() const {
    return (this->math + this->physic + this->chemistry) / 3;
}

void Student::display() {
    cout << "Name: " << this->name << '\n'
         << "Point math: " << this->math << '\n'
         << "Point physic: " << this->physic << '\n'
         << "Point chemistry: " << this->chemistry << '\n'
         << "Average: " << this->avgPoint() << '\n';
}

vector<Student> Student::getStudentMaxAvg(vector<Student> vt) {
    double maxPoint = 0;
    vector<Student> res;
    for (const auto & i : vt) {
        maxPoint = max(maxPoint, i.avgPoint());
    }
    for (auto & i : vt) {
        if (i.avgPoint() == maxPoint) {
            res.emplace_back(i);
        }
    }
    return res;
}

vector<Student> Student::getStudentMaxMath(vector<Student> vt) {
    double maxMath = 0;
    vector<Student> res;
    for (auto & i : vt) {
        maxMath = max(maxMath, i.math);
    }
    for (auto & i : vt) {
        if (i.math == maxMath) {
            res.emplace_back(i);
        }
    }
    return res;
}

vector<Student> Student::getStudentMaxPhysic(vector<Student> vt) {
    double maxPhysic = 0;
    vector<Student> res;
    for (auto & i : vt) {
        maxPhysic = max(maxPhysic, i.physic);
    }
    for (auto & i : vt)
        if (i.physic == maxPhysic) {
            res.emplace_back(i);
        }

    return res;
}

vector<Student> Student::getStudentMaxChemistry(vector<Student> vt) {
    double maxChemistry = 0;
    vector<Student> res;
    for (auto & i : vt) {
        maxChemistry = max(maxChemistry, i.chemistry);
    }
    for (auto & i : vt) {
        if (i.chemistry == maxChemistry) {
            res.emplace_back(i);
        }
    }
    return res;
}
