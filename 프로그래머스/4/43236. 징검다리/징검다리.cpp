#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool Check(const vector<int>& rocks, const ll mid, const int n)
{
    int cnt = 0;
    int prev = 0;
    for(int i=1;i<rocks.size();++i)
    {
        if(rocks[i]- prev < mid)
        {
            ++cnt;
        }
        else
        {
            prev = rocks[i];
        }
    }
    return n >= cnt;
}
int solution(int distance, vector<int> rocks, int n)
{
    // 0 2 11 14 17 21 25
    // 2 9 3 4 4
    ll l=1;
    ll r = distance+1;
    ll ans =0;
    rocks.emplace_back(0);
    rocks.emplace_back(distance);
    sort(rocks.begin(),rocks.end());
    while(l < r)
    {
        const auto mid = (l+r)/2LL;
        if(Check(rocks,mid,n))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    return ans;
}