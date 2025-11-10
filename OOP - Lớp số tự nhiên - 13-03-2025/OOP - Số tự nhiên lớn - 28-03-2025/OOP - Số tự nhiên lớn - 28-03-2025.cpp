// OOP - Số tự nhiên lớn - 28-03-2025.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

class big_integer {
private:
    string value;
    bool is_negative;

    static string remove_leading_zeros(const string& s) {
        size_t pos = s.find_first_not_of('0');
        return (pos != string::npos) ? s.substr(pos) : "0";
    }

    static bool abs_less(const string& a, const string& b) {
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
    }

    static string add_strings(const string& a, const string& b) {
        string res;
        int carry = 0, i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            carry = sum / 10;
            res += (sum % 10 + '0');
        }
        reverse(res.begin(), res.end());
        return res;
    }

    static string subtract_strings(const string& a, const string& b) {
        string res;
        int borrow = 0, i = a.size() - 1, j = b.size() - 1;
        while (i >= 0) {
            int digit_a = a[i--] - '0';
            int digit_b = (j >= 0) ? b[j--] - '0' : 0;
            int diff = digit_a - digit_b - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            }
            else borrow = 0;
            res += (diff + '0');
        }
        reverse(res.begin(), res.end());
        return remove_leading_zeros(res);
    }

    static string multiply_strings(const string& a, const string& b) {
        if (a == "0" || b == "0") return "0";
        int n = a.size(), m = b.size();
        string res(n + m, '0');
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int mul = (a[i] - '0') * (b[j] - '0');
                int sum = mul + (res[i + j + 1] - '0');
                res[i + j + 1] = (sum % 10) + '0';
                res[i + j] += sum / 10;
            }
        }
        return remove_leading_zeros(res);
    }

    static pair<string, string> divide_strings(const string& dividend, const string& divisor) {
        if (divisor == "0") throw runtime_error("Divide by zero!");
        if (abs_less(dividend, divisor)) return { "0", dividend };

        string quotient, remainder;
        for (char digit : dividend) {
            remainder += digit;
            remainder = remove_leading_zeros(remainder);
            int count = 0;
            while (!abs_less(remainder, divisor)) {
                remainder = subtract_strings(remainder, divisor);
                count++;
            }
            quotient += (count + '0');
        }
        return { remove_leading_zeros(quotient), remove_leading_zeros(remainder) };
    }

public:
    // ✅ Constructor mặc định
    big_integer() : value("0"), is_negative(false) {}

    big_integer(string val) {
        is_negative = false;
        if (val.empty())
            throw invalid_argument("Chuoi rong!");

        if (val[0] == '-') {
            is_negative = true;
            val = val.substr(1);
        }

        if (val.empty() || val.find_first_not_of("0123456789") != string::npos)
            throw invalid_argument("So khong hop le!");

        value = remove_leading_zeros(val);
        if (value == "0") is_negative = false;
    }

    // Toán tử cộng
    big_integer operator+(const big_integer& other) const {
        if (is_negative == other.is_negative) {
            return big_integer((is_negative ? "-" : "") + add_strings(value, other.value));
        }
        else {
            if (abs_less(value, other.value))
                return big_integer((other.is_negative ? "-" : "") + subtract_strings(other.value, value));
            else
                return big_integer((is_negative ? "-" : "") + subtract_strings(value, other.value));
        }
    }

    // Toán tử trừ
    big_integer operator-(const big_integer& other) const {
        big_integer temp = other;
        temp.is_negative = !temp.is_negative;
        return *this + temp;
    }

    // Toán tử nhân
    big_integer operator*(const big_integer& other) const {
        big_integer result;
        result.value = multiply_strings(value, other.value);
        result.is_negative = (is_negative != other.is_negative) && result.value != "0";
        return result;
    }

    big_integer operator/(const big_integer& other) const {
        pair<string, string> result_pair = divide_strings(value, other.value);
        string quot = result_pair.first;

        big_integer result(quot);
        result.is_negative = (is_negative != other.is_negative) && result.value != "0";
        return result;
    }

    big_integer operator%(const big_integer& other) const {
        pair<string, string> result_pair = divide_strings(value, other.value);
        string rem = result_pair.second;

        big_integer result(rem);
        result.is_negative = is_negative && result.value != "0";
        return result;
    }


    // Toán tử xuất
    friend ostream& operator<<(ostream& os, const big_integer& num) {
        if (num.is_negative) os << "-";
        os << num.value;
        return os;
    }

    // Toán tử nhập
    friend istream& operator>>(istream& is, big_integer& num) {
        string input;
        is >> input;
        num = big_integer(input);
        return is;
    }
};

int main() {
    big_integer a, b;

    cout << "Nhap so a: ";
    cin >> a;

    cout << "Nhap so b: ";
    cin >> b;

    cout << "\nKET QUA:\n";
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;

    try {
        cout << "a / b = " << a / b << endl;
        cout << "a % b = " << a % b << endl;
    }
    catch (const exception& e) {
        cout << "Loi chia: " << e.what() << endl;
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
