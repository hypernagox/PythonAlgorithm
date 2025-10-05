#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
vector<map<int, int>> vals; // i번 인덱스의 광물을 캘때 곡괭이 : 비용을 맵핑하는 비용
const map<string, int> name2idx
{
    {"diamond",0},
     {"iron",1},
     {"stone",2},
};
constexpr const int costs[3][3]
{
    {1,1,1},
    {5,1,1},
    {25,5,1}
};
void UpdateCost(const int num_of_minerals[])
{
    map<int, int> temp;
    // 곡괭이 종류
    for (int a = 0; a < 3; ++a)
    {
        for (int b = 0; b < 3; ++b)
        {
            // a번째 곡괭이 사용시 총 비용 계산
            temp[a] += (num_of_minerals[b] * costs[a][b]);
        }
    }
    vals.emplace_back(move(temp));
}
int res = 1 << 20;
bool visited[3][11];
void GO(const int depth,vector<int>& picks, const int cost = 0)
{
    if (depth == vals.size())
    {
        res = min(res, cost);
        return;
    }
    if (0 == picks[0] && 0 == picks[1] && 0 == picks[2])
    {
        res = min(res, cost);
        return;
    }
    for (int i = 0; i < picks.size(); ++i)
    {
        if (picks[i] == 0)
        {
            continue;
        }
        //if (visited[i][depth + 1])continue;
        visited[i][depth + 1] = true;
        --picks[i];
        GO(depth + 1, picks, cost + vals[depth][i]);
        ++picks[i];
    }
}
int solution(vector<int> picks, vector<string> minerals)
{
    int num_of_minerals[3] = {};
    int cnt = 0;
    for (int i = 0; i < minerals.size(); ++i)
    {
        const auto idx = name2idx.find(minerals[i])->second;
        ++num_of_minerals[idx];
        ++cnt;
        if (5 == cnt)
        {
            UpdateCost(num_of_minerals);
            cnt = 0;
            memset(num_of_minerals, 0, sizeof(num_of_minerals));
        }
    }
    if (0 != cnt)
    {
        UpdateCost(num_of_minerals);
    }
    GO(0, picks);
    return res;
}