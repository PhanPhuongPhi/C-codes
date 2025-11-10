// PPP_do_an_cuoi_ky Intro_AI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "TSP_Header.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int n;

int main()
{
    // Đọc file .txt ghi dữ liệu đầu vào
    ifstream inputFile("TSP_input_data.txt");

    if (!inputFile.is_open())
    {
        cerr << "Khong the mo file TSP_input_data.txt" << endl;
        return 1;
    }

    vector<diem> nodes;
    inputFile >> n; // Đọc số điểm khai báo từ file TSP_input_data.txt
    // Số cạnh tối đa = n * (n - 1) * 0.5
    diem kho_hang;  
    inputFile >> kho_hang.x >> kho_hang.y;
    kho_hang.label = "Kho";
    nodes.push_back(kho_hang);

    for (int i = 1; i < n; ++i)
    {
        diem p;
        inputFile >> p.x >> p.y;
        p.label = "Diem " + to_string(i);
        nodes.push_back(p);
    }

    inputFile.close();

    cout << nodes.size() << " diem: " << endl;
    for (const auto& p : nodes)
        cout << p.label << ": (" << p.x << ", " << p.y << ")" << endl;

    auto traversing_path = a_star(nodes);
    // Kiểm tra có đường đi hay không 
    if (traversing_path.first.empty())
    {
        cout << "Khong tim thay lo trinh hop le!" << endl;
        return 1;
    }
    else 
    {
        cout << "Lo trinh toi uu: ";
        for (size_t i = 0; i < traversing_path.first.size(); ++i)
        {
            int idx = traversing_path.first[i];
            cout << nodes[idx].label; 
            if (i != traversing_path.first.size() - 1)
                cout << " -> ";
        }
    }

    cout << " -> " << nodes[0].label << endl;
    cout << "Tong quang duong: " << traversing_path.second << "\n";

    return 0;
}

