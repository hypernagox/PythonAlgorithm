#include <bits/stdc++.h>
using namespace std;
vector<int> adj[250001];
bool visited[250001];
int far_node;
int far_dist=0;
void GetFarNode(const int cur,const int cost)
{
    if(far_dist < cost)
    {
        far_dist=cost;
        far_node=cur;
    }
    visited[cur]=true;
    for(const auto next:adj[cur])
    {
        if(visited[next])continue;
        GetFarNode(next,cost+1);
    }
}
int res =0;
void GetDist(const int far_a,const int far_b, const int cur ,const int cost)
{
    res = max(res,cost);
    visited[cur]=1;
    for(const auto next : adj[cur])
    {
        if(visited[next])continue;
        if(next == far_a)continue;
        if(next == far_b)continue;
        GetDist(far_a,far_b,next,cost + 1);
    }
}
int solution(int n, vector<vector<int>> edges) 
{
    for(const auto& e :edges)
    {
        adj[e[0]].emplace_back(e[1]);
        adj[e[1]].emplace_back(e[0]);
    }
    GetFarNode(1,0);
    const auto far_a = far_node;
    far_dist=0;
    memset(visited,0,sizeof(visited));
    GetFarNode(far_a,0);
    const auto far_b = far_node;
   // cout<<far_dist;
  //  cout<<far_a<<" "<<far_b<<" "<<far_dist<<endl;
     memset(visited,0,sizeof(visited));
    GetDist(far_a,far_b,far_a,0);
      memset(visited,0,sizeof(visited));
    GetDist(far_a,far_b,far_b,0);
    return res;
}