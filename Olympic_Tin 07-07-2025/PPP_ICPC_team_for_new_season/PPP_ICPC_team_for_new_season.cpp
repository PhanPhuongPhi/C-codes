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

