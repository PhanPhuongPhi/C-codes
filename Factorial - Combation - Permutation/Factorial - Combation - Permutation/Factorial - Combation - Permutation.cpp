// Factorial - Combation - Permutation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <limits>
using namespace std;
using ul = unsigned long;

ul giai_thua(ul n)
{
    if (n == 0 || n == 1) return 1;
    else if (n >= 2)
    {
        ul fact;
        fact = giai_thua(n - 1) * n;
        return fact;
    }
    else
        return -1;
}

ul to_hop(ul n, ul k)
{
    ul tohop;
    ul m, j;
    if (k == 0 || k == n)
        return 1;
    else if (0 < k && k < n)
    {
        m = n - 1;
        j = k - 1;
        tohop = to_hop(m, k) + to_hop(m, j);
        return tohop;
    }
    else
        return -1;
}

ul chinh_hop(ul n, ul k)
{
    ul chinhhop;
    if (k > n)
        return -1;
    else if (k == 0)
        return 1;
    else
        chinhhop = n * chinh_hop(n - 1, k - 1);
    return chinhhop;
}

int main()
{
    ul a, b;
    
    int choice;
    do {
        cout << "\n===== Moi ban lua chon =====" << endl;
        cout << "1. Tinh giai thua" << endl;
        cout << "2. Tinh to hop" << endl;
        cout << "3. Tinh chinh hop" << endl;
        cout << "Lua chon: ";
        cin >> choice;
        cin.ignore();

        cout << "Nhap so a: ";
        cin >> a;
        cout << "Nhap so b: ";
        cin >> b;

        if (choice == 1)
        {
            cout << "Giai thua cua " << a << " = " << giai_thua(a) << endl;
            cout << "Giai thua cua " << b << " = " << giai_thua(b) << endl;

        }
        else if (choice == 2) 
        {
            cout << "To hop chap " << b << " cua " << a << " = " << to_hop(a, b) << endl;
        }
        else if (choice == 3)
        {
            cout << "Chinh hop chap " << b << " cua " << a << " = " << chinh_hop(a, b) << endl;
        }
        else if (choice == 0)
        {
            cout << "Ket thuc chuong trinh.\n";
            break;
        }
        else
        {
            cout << "Lua chon khong hop le!\n";
        }
    } while (true);
    
    return 0;
}


