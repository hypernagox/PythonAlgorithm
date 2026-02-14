#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> req[6];
int mentors[6];
int K;
int N;
int GetWaitTime(const int type)
{
    const auto num_mentors = mentors[type];
    priority_queue<int,vector<int>,greater<int>> pq; // 끝나는 시간
    for(int i=0;i<num_mentors;++i)pq.emplace(0);
    int res = 0;
    for(const auto [start_time, run_time] : req[type])
    {
        const auto early_end_time = pq.top();
        pq.pop();
        if(early_end_time <= start_time)
        {
            pq.emplace(start_time + run_time);
        }
        else
        {
            res += (early_end_time - start_time);
            pq.emplace(early_end_time + run_time);
        }
    }
    return res;
}
int ans = 987654321;
void GO(const int idx, const int start)
{
    if(0 == idx)
    {
        int s = 0;
        for(int i = 0;i < K;++i)
        {
            s += GetWaitTime(i);
        }
        ans = min(ans,s);
        return;
    }
    for(int i = start;i < K;++i)
    {
        ++mentors[i];
        GO(idx - 1,i);
        --mentors[i];
    }
}
int solution(int k, int n, vector<vector<int>> reqs)
{
    for(const auto& v :reqs)
    {
        req[v[2] - 1].emplace_back(v[0], v[1]);
    }
    N = n;
    fill(mentors,mentors + k,1);
    GO(n - (K = k),0);
    return ans;
}