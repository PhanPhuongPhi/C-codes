// OOP - Prefix and Postfix Overload - 07-03-2025.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class counter {
private:
    double value;

public:
    counter(double v = 0) : value(v) {}
    counter& operator++()
    {
        ++value;
        return *this;
    }

    counter& operator++(int)
    {
        counter temp = *this;
        ++value;
        return temp;
    }

    void display() const 
    {
        cout << value;
    }
};

int main()
{
    counter c(9);

    cout << "Gia tri ban dau: ";
    c.display();
    cout << endl;

    cout << "Sau khi su dung prefix (++c): ";
    (++c).display(); // tăng và hiển thị giá trị mới
    // '(++c)' tương đương với 'c.operator++()'
    cout << endl;

    cout << "Su dung postfix (c++): ";
    c.display(); // hiển thị giá trị cũ trước khi tăng
    cout << endl;

    cout << "Gia tri hien tai: ";
    c.display(); // hiển thị giá trị sau khi tăng
    cout << endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
