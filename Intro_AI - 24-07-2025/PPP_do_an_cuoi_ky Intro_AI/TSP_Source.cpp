#include <queue>
#include <cmath>
#include <unordered_set>
#include <limits>
#include <iomanip>
#include "TSP_Header.h"
#include <iostream>
using namespace std;

double dist_calc(const diem& a, const diem& b)
{
	double path_dist = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	return path_dist;
}

double heuristic_distance(const vector<diem>& nodes, const vector<int>& remaining, int current)
{
    if (remaining.empty()) 
        return dist_calc(nodes[current], nodes[0]); // quay về kho
    double min_dist = numeric_limits<double>::max();
    for (int i : remaining)
        min_dist = min(min_dist, dist_calc(nodes[current], nodes[i]));
    return min_dist;
}

pair<vector<int>, double> a_star(const vector<diem>& nodes)
{
    int n = nodes.size();
    priority_queue<duong_di> pq;    // Tạo hàng đợi ưu tiên pq (min-heap dựa trên g + h)
    pq.push({ {0}, 0.0, 0.0 });

    // Khởi tạo kết quả tốt nhất
    pair<vector<int>, double> final_result;
    double best_way = numeric_limits<double>::max();

    while (!pq.empty()) // Trong khi vẫn có đường đi trong hàng đợi
    {
        duong_di current = pq.top(); pq.pop();

        // Duyệt qua các đỉnh
        if (current.lo_trinh.size() == n) 
        {
            double new_cost = dist_calc(nodes[current.lo_trinh.back()], nodes[0]);  // Tính thêm chi phí quay về điểm đầu
            double total_coverage = current.cost + new_cost;

            if (total_coverage < best_way)
            {
                best_way = total_coverage;
                final_result = { current.lo_trinh, best_way };  // Nếu nhỏ hơn kết quả tốt nhất hiện tại thì cập nhật kết quả
            }
            continue;
        }

        unordered_set<int> visited(current.lo_trinh.begin(), current.lo_trinh.end());   // Lưu lại các điểm đã đi qua

        for (int i = 0; i < n; ++i)
        {
            if (visited.count(i))
                continue;

            vector<int> new_path = current.lo_trinh;
            new_path.push_back(i);  // Thêm điểm i vào lộ trình hiện tại.
            double new_cost = current.cost + dist_calc(nodes[current.lo_trinh.back()], nodes[i]);

            unordered_set<int> new_visited = visited;
            new_visited.insert(i);
            // Tạo danh sách các điểm giao hàng chưa ghé 
            vector<int> remaining;
            for (int j = 0; j < n; ++j)
                if (!new_visited.count(j))
                    remaining.push_back(j);

            double h = heuristic_distance(nodes, remaining, i); // Gọi hàm heuristic_distance để tính chi phí ước lượng còn lại 
            pq.push({ new_path, new_cost, new_cost + h });
        }
    }

    return final_result;
}