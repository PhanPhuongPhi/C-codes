#pragma once
#ifndef _TSP_H
#define _TSP_H

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

struct diem {
    double x;
    double y;
    string label;
};

struct duong_di {
    vector<int> lo_trinh;   // Lưu đường đi hiện tại
    double cost;    // Chi phí thực tế đã đi
    double estimated_total;  // Chi phí ước lượng (cost + heuristic)

    // Nạp chồng toán tử '<' để ưu tiên estimated_total thấp hơn
    bool operator<(const duong_di& other) 
    const 
    {
        return estimated_total > other.estimated_total; // Với hàng đợi ưu tiên min-heap
    }     
};

double dist_calc(const diem& a, const diem& b); // Tính khoảng cách giữa các điểm
// Tính khoảng cách giữa điểm này và các điểm lân cận để tìm đường đi ngắn nhất
double heuristic_distance(const vector<diem>& nodes, const vector<int>& remaining, int current);
// Sử dụng thuật toán A* để tìm đường đi
pair<vector<int>, double> a_star(const vector<diem>& nodes);

#endif // !_TSP_H
