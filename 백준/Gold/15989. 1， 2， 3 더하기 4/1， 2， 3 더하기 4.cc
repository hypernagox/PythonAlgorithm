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
ll memo[10001][3];
ll GO(const int n, const int start)
{
    if (n < 0)return 0;
    if (n == 0)return 1;
    auto& ref = memo[n][start];
    if (~ref)return ref;
    ll res = 0;
    for (int i = start; i <= 3; ++i)
    {
        res += GO(n - i, i);
    }
    return ref = res;
}
void Solve() noexcept
{
    int t; cin >> t;
    memset(memo, -1, sizeof(memo));
    while (t--)
    {
        int n; cin >> n;
        cout << GO(n, 1) << '\n';
    }
}
int main()
{
    FastIO();
    Solve();
}