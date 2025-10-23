#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
const map<char, pair<int, int>> m
{
    {'R',{0,1}},
   {'L',{0,-1}},
   {'U',{1,0}},
    {'D',{-1,0}},
};
int solution(string dirs) 
{
    int answer = 0;
    map<pair<int, int>, set<pair<int, int>>> visited;
    pair<int, int> cur{ 5,5 };
    for (const auto d : dirs)
    {
        const auto [y, x] = m.find(d)->second;
        const auto ny = cur.first + y;
        const auto nx = cur.second + x;
        if (ny < 0 || nx < 0 || ny >10 || nx>10)continue;
        const auto next = make_pair(ny, nx);
        auto temp1 = next;
        auto temp2 = cur;
        if (temp1 > temp2)swap(temp1, temp2);
        if (visited[temp1].emplace(temp2).second)
        {
            ++answer;
        }
        cur = next;
    }
    return answer;
}