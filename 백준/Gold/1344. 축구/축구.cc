#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
double a, b;
double dp[20][20][20];
bool IsPrime[22];
void CHE()
{
    for (auto& i : IsPrime)for (auto& j : IsPrime)j = true;
    IsPrime[0] = IsPrime[1] = false;
    for (long long p = 2; p * p < 22; ++p) 
    {
        if (!IsPrime[p]) continue;
        for (long long x = p * p; x < 22; x += p) 
        {
            IsPrime[x] = false;
        }
    }
}
double GO(const int idx, const int cur_a,const int cur_b)
{
    if (idx == 18)
    {
        return IsPrime[cur_a] || IsPrime[cur_b] ? 1. : 0.;
    }
    auto& ref = dp[idx][cur_a][cur_b];
    if (ref > -0.5)return ref;
    ref = 0.;
    ref += GO(idx + 1, cur_a + 1, cur_b)* a * (1. - b);
    ref += GO(idx + 1, cur_a, cur_b + 1)* b * (1. - a);
    ref += GO(idx + 1, cur_a + 1, cur_b + 1)* a* b;
    ref += GO(idx + 1, cur_a, cur_b)* (1. - a)* (1. - b);
    return ref;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    CHE();
    int x, y; cin >> x >> y;
    a = (double)x / 100.;
    b = (double)y / 100.;
    cout << GO(0, 0, 0);
}