// Financial management.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double bank_account(double x[])
{
    double money_sum = 0;
    for (int i = 0; i < 12; i++)
    {
        cin >> x[i];
        money_sum += x[i];
    }
    return money_sum / 12;
}

int main()
{
    double x[12];   // Array lưu số tiền của 12 tháng 
    double hoa_don = bank_account(x);
    cout << fixed << setprecision(2) << hoa_don;
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
