// OOP - Lớp số tự nhiên - 13-03-2025.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

class so_tu_nhien {
public:
    char s[512];

public:
    so_tu_nhien() {
        strcpy(s, "0"); // Initialize as zero
    }

    so_tu_nhien(const char* num) {
        strncpy(s, num, 255);
        s[255] = '\0';
    }

    // Toán tử cộng 2 số tự nhiên (big number addition)
    so_tu_nhien operator + (const so_tu_nhien& other) {
        so_tu_nhien result;
        char temp[256] = { 0 };

        int len1 = strlen(s);
        int len2 = strlen(other.s);
        int carry = 0, sum = 0;
        int i = len1 - 1, j = len2 - 1, k = 0;

        while (i >= 0 || j >= 0 || carry) {
            int num1 = (i >= 0) ? s[i] - '0' : 0;
            int num2 = (j >= 0) ? other.s[j] - '0' : 0;
            sum = num1 + num2 + carry;
            carry = sum / 10;
            temp[k++] = (sum % 10) + '0';
            i--; j--;
        }

        temp[k] = '\0';
        reverse(temp, temp + k);
        strcpy(result.s, temp);
        return result;
    }

    // Prefix ++ (increment the number by 1)
    so_tu_nhien& operator++() {
        *this = *this + so_tu_nhien("1");
        return *this;
    }

    // Postfix ++
    so_tu_nhien operator++(int) {
        so_tu_nhien temp = *this;
        ++(*this);
        return temp;
    }

    void display() {
        cout << s << endl;
    }
};

class so_nguyen : public so_tu_nhien {
    char sign;
public:
    // Toán tử + 2 số nguyên 
    so_nguyen operator + (so_nguyen);
};

int main()
{
    std::cout << "Hello World!\n";
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
