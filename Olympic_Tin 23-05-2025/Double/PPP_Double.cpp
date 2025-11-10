// Double.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main() 
{
    while (true) 
    {
        int a[20];  // Mảng tối đa 20 phần tử
        int n = 0;  // Đếm số phần tử trong dòng hiện tại
        int x;

        cout << "Nhap cac so nguyen (ket thuc bang 0, -1 de ket thuc chuong trinh):\n";

        // Đọc một dòng dữ liệu
        while (cin >> x && x != 0) 
        {
            if (x == -1) return 0; // Kết thúc toàn bộ chương trình
            a[n++] = x;
        }

        // Đếm số phần tử là gấp đôi phần tử khác
        int count = 0;  // Biến đếm số lượng phần tử là gấp đôi của phần tử khác
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (i != j && a[i] == 2 * a[j]) 
                {
                    count++;
                    break; // Tránh đếm trùng
                }
            }
        }

        cout << count << endl;  // Trả về kết quả
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
