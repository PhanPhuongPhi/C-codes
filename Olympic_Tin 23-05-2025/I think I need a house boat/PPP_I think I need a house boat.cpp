// I think I need a house boat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;
#define pi 3.14159

int main()
{
    double kq;
    double x, y;    // Tọa độ mảnh đất
    int n;
    cin >> n;   // Số test case 
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        kq = (pow(x, 2) + pow(y, 2)) / 100;
        cout << "Property " << i + 1 << ": This property will begin eroding in year will begin eroding in year: " << ceil(kq);
    }
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
