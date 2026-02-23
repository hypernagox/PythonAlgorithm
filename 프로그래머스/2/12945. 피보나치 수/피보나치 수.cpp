#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll memo[100001];
constexpr const ll MOD = 1234567;
ll GO(const int cur)
{
    if(cur==0)return 0;
    if(cur == 1)return 1;
    if(cur == 2)return 1;
    auto& ref = memo[cur];
    if(ref)return ref;
    return ref = ((GO(cur -1) % MOD) + (GO(cur - 2) % MOD) ) % MOD;
}
int solution(int n) 
{
    return GO(n);
}