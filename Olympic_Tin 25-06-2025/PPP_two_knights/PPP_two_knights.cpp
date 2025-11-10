// PPP_two_knights.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;
using ul = unsigned long;

ul n;   // Số ô bàn cờ 

ul find_ways(ul k)
{
    // Số cách tối đa đặt 2 quân mã lên bàn cờ 
    ul knights_placements = (pow(k, 2) * (pow(k, 2) - 1)) / 2;

    // Trường hợp 2 quân mã tấn công nhau trên bàn cờ 
    ul knights_attacks = 4 * (k - 1) * (k - 2);

    return knights_placements - knights_attacks;    // Trả về số cách xếp 2 quân mã cuối cùng 
}

int main()
{
    cin >> n;

    for (ul k = 1; k <= n; k++)
        cout << find_ways(k) << " ";
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
