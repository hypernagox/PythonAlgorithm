#include <bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;
int counsellers[6];
int K;
int N;
vector<pi> human[6];
int GetWaitTime(const int type)
{
    const auto num_coun = counsellers[type];
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<num_coun;++i)
    {
        pq.emplace(0);
    }
    int wait_time = 0;
    for(const auto [s, e] : human[type])
    {
        const auto end_time = pq.top();
        pq.pop();
        if(end_time > s)
        {
            wait_time += (end_time - s);
        }
        pq.emplace(max(end_time,s) + e);
    }
    return wait_time;
}
int answer = 987654321;
void GO(const int cur, const int start)
{
    if(cur == N)
    {
        int s = 0;
        for(int i=0;i<K;++i)
        {
            s += GetWaitTime(i);
        }
        answer = min(answer,s);
        return;
    }
    for(int i=start; i < K ;++i)
    {
        ++counsellers[i];
        GO(cur+1,i);
        --counsellers[i];
    }
}
int solution(int k, int n, vector<vector<int>> reqs) 
{
    K = k;
    N = n - k;
    fill(counsellers,counsellers + 6,1);
    for(const auto& r :reqs)
    {
        human[r[2] - 1].emplace_back(r[0],r[1]);
    }
    GO(0 , 0);
    return answer;
}