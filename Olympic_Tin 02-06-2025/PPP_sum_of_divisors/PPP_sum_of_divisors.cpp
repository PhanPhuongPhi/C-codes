// PPP_sum_of_divisors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
#define ul unsigned long

const ul mod = 1e9 + 7;
ul n;

ul x, y, p;

ul power(ul x, ul y, ul p)
{
    ul kq = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            kq = (kq * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return (kq + p) % p;
}

ul mod_inv(ul x)
{
    return power(x, mod - 2, mod);
}

ul sum_calc(ul n)
{
    return (((n % mod) * ((n + 1) % mod)) % mod) * mod_inv(2) % mod;
}

ul div_sum_calc(ul n)
{
    ul ans = 0;
    ul l = 1;

    while (l <= n) {
        ul k = n / l;
        ul r = n / k;

        ans = (ans + k % mod * ((sum_calc(r) - sum_calc(l - 1) + mod) % mod)) % mod;
        l = r + 1;
    }
    return ans;
}

int main()
{
    cin >> n;
    cout << div_sum_calc(n) << endl;
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
