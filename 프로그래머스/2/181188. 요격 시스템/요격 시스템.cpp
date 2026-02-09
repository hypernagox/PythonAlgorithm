#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> targets)
{
    vector<pair<int,int>> missles;
    missles.reserve(targets.size());
    for(const auto& v : targets)
    {
        missles.emplace_back(v[1],v[0]);
    }
    sort(missles.begin(),missles.end());
    int cur_idx = 0;
    int ans = 1;
    for(int i=1;i<missles.size();++i)
    {
        if(missles[cur_idx].first <= missles[i].second)
        {
            ++ans;
            cur_idx = i;
        }
    }
    return ans;
}