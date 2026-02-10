#include <bits/stdc++.h>
using namespace std;
vector<int> adj[200001];
bool visited[200001];
unordered_map<int,int> before;
void GO(const int cur)
{
    if(visited[cur])return;
    const auto iter = before.find(cur); // 전에 가야할거있나?
    if(before.end() != iter)
    {
        if(!visited[iter->second])
        {
            adj[iter->second].emplace_back(cur);
            return;
        }
    }
    visited[cur]=true;
    for(const auto next : adj[cur])
    {
        if(visited[next])continue;
        GO(next);
    }
}
bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) 
{
    for(const auto& e: path)
    {
        adj[e[0]].emplace_back(e[1]);
        adj[e[1]].emplace_back(e[0]);
    }
    before.reserve(order.size());
    for(const auto& v: order)
    {
        before.emplace(v[1],v[0]);
    }
    GO(0);
    for(int i=0;i<n;++i)if(!visited[i])return false;
    return true;
}