#include <bits/stdc++.h>
using namespace std;
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
constexpr const int INF = static_cast<int>(1e9) + 1;
constexpr const int MIN_INF = -INF;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
constexpr const int coin[]{ 1,2,5,7 };
ll memo[100001];
ll GO(const ll cur_money)
{
    if (cur_money < 0)return INF;
    if (cur_money == 0)return 0;
    auto& ref = memo[cur_money];
    if (~ref)return ref;
    ll res = INF;
    for (int i = 0; i < 4; ++i)
    {
        res = min(res, GO(cur_money - coin[i]) + 1);
    }
    return ref = res;
}
void Solve()noexcept
{
    int n; cin >> n;
    memset(memo, -1, sizeof(memo));
    cout << GO(n);
}
int main()
{
    FastIO();
    Solve();
}