#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> top;
int N;
constexpr const ll MOD = 10007;
ll memo[100001][2];
long long GO(const int i, const int right)
{
    auto& ref = memo[i][right];
    if(ref)return ref;
    if(0 == i)
    {
        if(right)
        {
            return 1;
        }
        else
        {
            return top[i] ? 3 : 2;
        }
    }
    const int k1 = (top[i] ? 2 : 1);
    const int k2 = (top[i] ? 3 : 2);
    if(right)
    {
        return ref = (GO(i-1,0) + GO(i-1,1)) % MOD;
    }
    else
    {
       return ref = (GO(i-1,0) * k2 + GO(i-1,1) * k1) % MOD;
    }
}
int solution(int n, vector<int> tops)
{
    top.swap(tops);
    N=n;
    return (GO(n-1,0) + GO(n-1,1)) %MOD;
}