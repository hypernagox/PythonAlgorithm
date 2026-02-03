#include <bits/stdc++.h>
using namespace std;
vector<pair<long long,long long>> m;
vector<pair<long long,long long>> acc_v;
long long solution(vector<vector<int>> land, int P, int Q) 
{
    vector<long long> temp;
    temp.reserve(land.size()*land.size());
   for(const auto& v:land)
   {
       for(const auto i : v)
       {
           temp.emplace_back(i);
           //++m[i];
       }
   }
    sort(temp.begin(),temp.end());
    for(auto it = temp.begin();it != temp.end();)
    {
        const auto [lb,up]=equal_range(it,temp.end(),*it);
        //if(lb == up)break;
        m.emplace_back(*it,(up-lb));
       // m[*it] = (up-lb);
        it = up;
    }
    const auto MAX_V = m.rbegin()->first;
    long long s = 0;
    long long cur_cost = 0;
    acc_v.reserve(m.size());
    for(const auto [h,num]:m)
    {
        s += num;
        acc_v.emplace_back(h,s);
        cur_cost += (MAX_V - h) * num * P;
    }
    long long answer = cur_cost;
    for(long long i = (long long)acc_v.size() - 2;i >= 0 ;--i)
    {
        // 작은애들 모임
        const auto [h1,n1] = acc_v[i];
        
        // 큰애들모임
        const auto [h2,n2] = acc_v[i + 1];
        
        const auto a = (h2-h1) * P * n1;
        const auto b = (s - n1) * Q * (h2 - h1);
        cur_cost = cur_cost - a + b;
        answer = min(answer,cur_cost);
    }
    return answer;
}