#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
constexpr const int dy[]{ -1,0,1,0 };
constexpr const int dx[]{ 0,1,0,-1 };
struct Point
{
    int y, x;
    int cost;
    Point(int a, int b, int c) :y{ a }, x{ b }, cost{ c } {}
    const auto operator<(const Point& a)const noexcept { return cost < a.cost; }
};
map<pair<int, int>, int> bestDists;
set<pair<int, int>> visited;
map<pair<int, int>, vector<Point>> adj;
int solution(vector<vector<int>> land, int height) 
{
    int answer = 0;
    for (int i = 0; i < land.size(); ++i)
    {
        for (int j = 0; j < land.front().size(); ++j)
        {
            const auto cur_h = land[i][j];
            for (int k = 0; k < 4; ++k)
            {
                const auto ny = i + dy[k];
                const auto nx = j + dx[k];
                if (ny < 0 || nx < 0 || ny >= land.size() || nx >= land.front().size())continue;
                const auto cost = abs(cur_h - land[ny][nx]) <= height ? 0 : abs(cur_h - land[ny][nx]);
                adj[{i, j}].emplace_back(ny, nx, cost);
                adj[{ny, nx}].emplace_back(i, j, cost);
            }
            bestDists[{i, j}] = 1 << 20;
        }
    }
    bestDists[{0, 0}] = 0;
    priority_queue<Point> pq;
    pq.emplace(0, 0, 0);
    while (!pq.empty())
    {
        auto [y, x, cost] = pq.top(); pq.pop();
        cost = -cost;
        if (!visited.emplace(y, x).second)continue;
        answer += cost;
        for (const auto& nexts : adj[{y, x}])
        {
            const auto new_cost = nexts.cost;
            if (bestDists[{nexts.y, nexts.x}] > new_cost)
            {
                bestDists[{nexts.y, nexts.x}] = new_cost;
                pq.emplace(nexts.y, nexts.x, -new_cost);
            }
        }
    }
    return answer;
}