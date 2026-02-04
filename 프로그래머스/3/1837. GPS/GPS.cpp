#include <bits/stdc++.h>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<set<int>> adj;
int memo[201][201];
vector<int> logs;
int GO(const int cur, const int seq)
{
    if(logs.size()-1 == seq)return logs.back() == cur ? 0 : 987654321;
    auto& ref = memo[cur][seq];
    if(~ref)return ref;
    int res = 987654321;
    for(const auto next:adj[cur])
    {
        if(next == logs[seq + 1])
        {
            res = min(res,GO(next,seq+1));
        }
        else
        {
            res = min(res,GO(next,seq+1) + 1);
        }
    }
    return ref = res;
}
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) 
{
    adj.clear();
    adj.resize(n+1);
    logs=gps_log;
    for(const auto& e :edge_list)
    {
        adj[e[0]].emplace(e[1]);
        adj[e[1]].emplace(e[0]);
        adj[e[0]].emplace(e[0]);
        adj[e[1]].emplace(e[1]);
    }
    memset(memo,-1,sizeof(memo));
    const auto res = GO(logs[0],0);
    return res >= 987654321 ? -1:res;
}