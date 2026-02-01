#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
bool visited[100001];
int memo[100001][2];
int GO(const int cur, const bool cur_light)
{
    auto& ref = memo[cur][cur_light];
    if(~ref)return ref;
    visited[cur]=true;
    int res = 0;
    // 여기서 불을 안켰으면 자식은 모두 켜야함
    if(!cur_light)
    {
        
        for(const auto next : adj[cur])
        {
            if(visited[next])continue;
            res += (GO(next,true));
        }
        visited[cur]=false;
        return ref = res + cur_light;
    }
    // 여기서 불을 켰다면 자식은 선택
    else
    {
        for(const auto next : adj[cur])
        {
            if(visited[next])continue;
            res += min((GO(next,true)),GO(next,false));
        }
        visited[cur]=false;
        return ref = res + cur_light;
    }
}
int solution(int n, vector<vector<int>> lighthouse)
{
    for(const auto& e : lighthouse)
    {
        adj[e[0]].emplace_back(e[1]);
        adj[e[1]].emplace_back(e[0]);
    }
    memset(memo,-1,sizeof(memo));
    return min(GO(1,0),GO(1,1));
}