// PPP_giant_pizza.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
using l = long;
const l MAX = 2e5 + 5;
l n, m; // Số thành viên trong gia đình và số topping trên pizza 
string no_valid = "IMPOSSIBLE";

vector<vector<l>> v(MAX);
vector<vector<l>> transpose_v(MAX);
vector<l> visited(MAX, 0);

void dfs(l u)
{
    visited[u] = 1;
}

int main()
{
    cin >> n >> m;
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
