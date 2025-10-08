#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int inDegree[1000002];
int outDegree[1000002];
bool visited[1000002];
vector<int> adj[1000002];
bool Is8 = false;
bool IsStick = false;
void GO(const int cur, const int root_node)
{
    // 진입차수 2가 하나라도있으면 8자
    if (2 == inDegree[cur])
    {
        Is8 = true;
    }
    else if (0 == inDegree[cur] || adj[cur].empty()) // 진입차수 0이 있으면 막대
    {
        IsStick = true;
    }
    if (visited[cur])return;
    visited[cur] = true;
    for (const auto next : adj[cur])
    {
        GO(next, root_node);
    }
}
vector<int> solution(vector<vector<int>> edges) 
{
    vector<int> answer; answer.resize(4, 0);
    int max_node_num = 1;
    for (const auto& edge : edges)
    {
        const auto from = edge[0];
        const auto to = edge[1];
        ++inDegree[to]; // 진입차수
        ++outDegree[from]; // 진출차수
        adj[from].emplace_back(to);
        max_node_num = max(max_node_num, max(from, to));
    }
    int target_node = -1;
    vector<int> targets;
    for (int i = 1; i <= max_node_num; ++i)
    {
        if (inDegree[i] == 0 && 1 != outDegree[i] && adj[i].size()!=1)
        {
            target_node = i;    // 범인 검거
            targets.emplace_back(i);
            //break;
        }
    }
    swap(targets.back(), targets.front());
    answer[0] = targets[0];
    // 자식들을 탐험
    for (const auto donuts : adj[target_node])
    {
        --inDegree[donuts]; // 진입차수 하나 제거
        GO(donuts, donuts);
        if (Is8)
        {
            ++answer[3];
        }
        else if (IsStick)
        {
            ++answer[2];
        }
        else
        {
            ++answer[1];
        }
        Is8 = IsStick = false;
    }
    return answer;
}