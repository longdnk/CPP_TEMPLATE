#include <iostream>
#include "header/Student.h"
#include <string>

//#include "bits/stdc++.h"

using namespace std;
// Coding and Funtion here

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.tie(nullptr);
    Student qallPeach = Student("Qall peach", 10, 9.5, 9.5);
    Student thanhTuSaoHoa = Student("Thanh Sao Hoa", 10, 8.5, 8.5);
    Student thanhXauTrai = Student("Thanh xau trai", 9.5, 9.5, 9.5);
    Student thanhKhongCoKu = Student("Thanh", 8.5, 8.5, 8.5);
    Student thanhCuaTraiDat = Student("Thanh", 7.5, 8.5, 9.5);
    Student thanhCuaZiot = Student("Thanh", 9, 8, 7);

    vector<Student> s { qallPeach, thanhTuSaoHoa, thanhXauTrai, thanhKhongCoKu, thanhCuaTraiDat, thanhCuaZiot };
    vector<Student> resMath = Student::getStudentMaxMath(s);
    vector<Student> resPhysic = Student::getStudentMaxPhysic(s);
    vector<Student> resChemistry = Student::getStudentMaxChemistry(s);
    vector<Student> resStudent = Student::getStudentMaxAvg(s);

    cout << "\t\t===Math List===\n";
    for (auto item: resMath) {
        item.display();
    }
    cout << "\t\t===End Math List===\n\n";

    cout << "\t\t===Physic List===\n";
    for (auto item: resPhysic) {
        item.display();
    }
    cout << "\t\t===End Physic List===\n\n";

    cout << "\t\t===Chemistry List=== \n";
    for (auto item: resChemistry) {
        item.display();
    }
    cout << "\t\t===End Chemistry List===\n\n";

    cout << "\t\t===Max avg list===\n\n";
    for (auto item: resStudent) {
        item.display();
    }
    cout << "\t\t===End max avg list" << "\n\n";
    string name = "Thang qall peach";
    cout << name << "\n";
}
