// OOP - GCD & LCM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

class gcd_lcm {
private:
    double a, b;

public:
    double gcd(double, double);
};

double gcd_lcm::gcd(double a, double b)
{
    double m, n;
    m = a;
    n = b;
    while (m > 0 && n > 0)
    {
        if (m > n)
            m -= n;
        else
            n -= m;
    }
    return m + n;
}

int main()
{
    double a, b;
    double uscln, bscnn;

    cout << "Nhap hai so a va b: ";
    cin >> a >> b;

    gcd_lcm obj;

    uscln = obj.gcd(a, b);
    bscnn = (a * b) / uscln; 

    cout << "Uoc so chung lon nhat cua " << a << " va " << b << " la: " << uscln << endl; 
    cout << "Boi so chung nho nhat cua " << a << " va " << b << " la: " << bscnn << endl;
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
