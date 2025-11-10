// PPP_Josephus_querries.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#define ll long long

ll n, k;	// The number of children and the position of the child
ll q;	// Number of querries

ll solve(ll n, ll k)
{
	if (n == 3 && k == 2)
		return 1;

	if (n == 1)
		return 1;

	if (k <= n / 2)
		return 2 * k;

	ll new_n = n / 2;
	ll new_k = k - ((n + 1) / 2); 
	
	ll kq = solve(new_n, new_k);

	if (n % 2 == 0)
		return 2 * kq - 1;
	else
		return 2 * kq + 1;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> q;
	while (q--) 
	{
		cin >> n >> k;
		cout << solve(n, k) << "\n";
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
