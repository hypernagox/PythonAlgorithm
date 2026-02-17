#include <bits/stdc++.h>
using namespace std;
struct Data
{
    long long food_time;
    long long idx;
    const auto operator<(const Data& d)const{
        if(food_time == d.food_time)return idx > d.idx;
        return food_time > d.food_time;
    }
    Data(int a,int b):food_time{a},idx{b}{}
};
int solution(vector<int> food_times, long long k) 
{
    priority_queue<Data> pq;
    for(int i=0;i<food_times.size();++i)
    {
        pq.emplace(food_times[i],i);
    }
    long long prev_time = 0;
    long long acc_time = 0;
    while(pq.size())
    {
        const auto N = pq.size();
        const auto [ft,i] = pq.top();
        const auto delta = ft - prev_time;
        const auto cost = delta * N;
        if(acc_time + cost > k)break;
        acc_time += cost;
        while(pq.size() && pq.top().food_time == ft)
        {
            pq.pop();
        }
        prev_time = ft;
    }
    if(pq.empty())return -1;
    k -= acc_time;
    vector<long long> ans;
    ans.reserve(pq.size());
    while(pq.size())
    {
        ans.emplace_back(pq.top().idx + 1);
        pq.pop();
    }
    sort(ans.begin(),ans.end());
    return ans[k % ans.size()];
}