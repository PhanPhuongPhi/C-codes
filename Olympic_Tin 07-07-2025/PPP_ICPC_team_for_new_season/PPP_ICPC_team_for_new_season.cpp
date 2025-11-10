// PPP_ICPC_team_for_new_season.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using l = long;
const l MAX = 1e5 + 5;
l n;


l tao_team(l n)
{
    vector<l> a(n);

    for (l i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

}

int main()
{
    cin >> n;
    cout << tao_team(n) << endl;
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
