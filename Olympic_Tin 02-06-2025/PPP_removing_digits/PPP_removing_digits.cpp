// PPP_removing_digits.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

const unsigned long max_val = 1e6;
unsigned long n;

unsigned long reduce_to_zero(unsigned long m)
{
    // Initialise dp[] to steps
    vector<unsigned long> dp(m + 1, max_val);

    dp[0] = 0;

    // Iterate for all elements
    for (unsigned long i = 0; i <= m; i++)
    {
        // For each digit in number i
        for (char c : to_string(i)) 
        {
            // Either select the number or do not select it
            dp[i] = min(dp[i], dp[i - (c - '0')] + 1);
        }
    }

    // dp[N] will give minimum step for N
    return dp[m];
}

int main()
{
    cin >> n;

    cout << reduce_to_zero(n) << endl;

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
