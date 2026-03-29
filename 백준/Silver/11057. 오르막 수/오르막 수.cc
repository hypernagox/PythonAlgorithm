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
constexpr const int MOD = 10007;
int memo[1001][10];
int GO(const int n, const int last)
{
    if (n == 1)return 1;
    if (last == 0)return 1;
    auto& ref = memo[n][last];
    if (~ref)return ref;
    return ref = (GO(n, last - 1) + GO(n - 1, last)) % MOD;
}
void Solve() noexcept
{   
    int n; cin >> n;
    int ans = 0;
    memset(memo, -1, sizeof(memo));
    for (int i = 0; i <= 9; ++i)
    {
        ans += GO(n, i) % MOD;
        ans %= MOD;
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}