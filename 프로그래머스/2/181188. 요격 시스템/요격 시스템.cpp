#include <bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;
int solution(vector<vector<int>> targets)
{
    vector<pi> v;
    for(const auto& e: targets)
    {
        v.emplace_back(e[1], e[0]);
    }
    sort(v.begin(),v.end());
    int cur_end = v[0].second;
    int ans = 0;
    for(const auto [end, start] : v)
    {
       if(cur_end <= start)
       {
           ++ans;
           cur_end = end;
       }
    }
    return ans;
}