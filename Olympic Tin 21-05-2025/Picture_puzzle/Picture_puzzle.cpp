// Picture_puzzle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int picture_puzzle(int n, int k) 
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1; // Cách duy nhất để ghép tổng = 0

    for (int i = 1; i <= n; ++i) 
    {
        for (int j = 1; j <= k; ++j) 
        {
            if (i - j >= 0) 
                dp[i] += dp[i - j];
        }
    }

    return dp[n];
}

int main() 
{
    int t;  // Số bộ test 
    cin >> t;
    while (t--) 
    {
        int n, k;   // Tổng số mảnh ghép và số mảnh ghép sử dụng:
        cin >> n >> k;
        cout << picture_puzzle(n, k) << endl;
    }

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
