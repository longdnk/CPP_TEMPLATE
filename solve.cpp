//
// Created by longdnk on 1/9/23.
//
#include <bits/stdc++.h>

using namespace std;

class Shape {
protected:
    const float pi = 2.0 * acos(0.0);
public:
    virtual auto input() -> void {}

    virtual auto calcArea() -> void {}

    virtual auto calcPerimeter() -> void {}
};

class Ellipse : public Shape {
protected:
    float a, b;
public:
    Ellipse(float a, float b) : a(a), b(b) {
        this->a = a;
        this->b = b;
    }

    Ellipse() {}

    auto input() -> void {
        cout << "Input a, b: ";
        cin >> a >> b;
    }

    auto calcArea() -> void {
        cout << "Area: " << (double) pi * a * b << '\n';
    }

    auto calcPerimeter() -> void {
        cout << "Perimeter: " << (double) pi * (a + b) << '\n';
    }
};

class Circle : public Shape {
protected:
    float r;
public:
    explicit Circle(float r) : r(r) {
        this->r = r;
    }

    Circle() {}

    auto input() -> void {
        cout << "Input r: ";
        cin >> r;
    }

    auto calcArea() -> void {
        cout << "Area: " << (double) pi * r * r << '\n';
    }

    auto calcPerimeter() -> void {
        cout << "Perimeter: " << (double) 2 * pi * r << '\n';
    }
};

int32_t main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
    // XỬ DỤNG tính đa xạ
    Shape *s[5];
    s[0] = new Ellipse();
    s[0]->input();
    s[0]->calcPerimeter();
    s[0]->calcArea();

    s[1] = new Circle();
    s[1]->input();
    s[1]->calcPerimeter();
    s[1]->calcArea();

    s[2] = new Ellipse(20, 30);
    s[2]->calcPerimeter();
    s[2]->calcArea();

    s[3] = new Circle(15);
    s[3]->calcPerimeter();
    s[3]->calcArea();

    // giải phóng dung lượng
    for (int i = 0; i < 4; ++i) {
        delete (s[i]);
    }
}
