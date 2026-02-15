#include <bits/stdc++.h>
using namespace std;
// if 간선이 추가되면 (루트가 되면)
// 홀수노드 -> 역홀수
// 짝수노드 -> 역짝수
// 역홀수 -> 홀수
// 역짝수 -> 짝수
// 0 -> 홀짝노드
// 1 -> 역홀짝노드
vector<int> adj[1000001];
int states[2];
bool visited[1000001];
int GetNodeType(const int node)
{
    const auto childs = adj[node].size() - 1;
    return (node & 1) != (childs & 1);
}
void GO(const int cur)
{
    if(visited[cur])return;
    visited[cur] = true;
    const auto type = GetNodeType(cur);
    ++states[type];
    for(const auto next : adj[cur])
    {
        if(visited[next])continue;
        GO(next);
    }
}
vector<int> solution(vector<int> nodes, vector<vector<int>> edges) 
{
    vector<int> answer(2,0);
    for(const auto& e : edges)
    {
        adj[e[0]].emplace_back(e[1]);
        adj[e[1]].emplace_back(e[0]);
    }
    for(const auto i : nodes)
    {
        if(visited[i])continue;
        if(0 == adj[i].size())
        {
            visited[i]=true;
            ++answer[i&1];
            continue;
        }
        GO(i);
        answer[0] += (1 == states[1]);
        answer[1] += (1 == states[0]);
        states[0] = states[1] = 0;
    }
    return answer;
}