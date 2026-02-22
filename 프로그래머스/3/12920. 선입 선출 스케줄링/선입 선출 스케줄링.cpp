#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// mid 시간일 때 처리 가능한 작업 수
ll Cal(const ll mid, const vector<int>& cores)
{
    ll s = cores.size();
    for(const auto i : cores)
    {
        s += (mid / (ll)i);
    }
    return s;
}
int solution(int n, vector<int> cores) 
{
    if(n <= cores.size())return n;
    ll l = 0;
    ll e = 1LL << 20;
    ll t = 0;
    while(l < e)
    {
        const auto mid = (l + e) / 2LL;
        const auto cnt = Cal(mid,cores);
        if(cnt >= n)
        {
            t = mid;
            e = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    ll ans = 0;
    ll prev_cnt = Cal(t - 1,cores); // 1초 덜 줬으면 몇 개 까지 작업이 가능한가?
    for(int i=0;i<cores.size();++i)
    {
        if(t % cores[i] == 0) // 작업을 완료하기 위한 최소시간 t에서 마지막 작업은 배수관계여야함
        {
            if(++prev_cnt == n) // t-1초에서 못다한 작업을 한개씩처리해서 n개에 도달하면
            {
               ans = i + 1;
               break;
            }
        }
    }
    return ans;
}