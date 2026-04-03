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
constexpr const int offset = 1000000;
ll memo[offset * 2 + 1];
bool visited[offset * 2 + 1];
constexpr const ll MOD = 1000000000;
ll GO1(const int num)
{
    if (num == -1)return 1;
    if (num == 1)return 1;
    if (num == 0)return 0;
    const auto pos = num + offset;
    if (visited[pos])return memo[pos];
    visited[pos] = 1;
    return memo[pos] = (GO1(num + 2) - GO1(num + 1)) % MOD;
}
ll GO2(const int num)
{
    if (num == -1)return 1;
    if (num == 1)return 1;
    if (num == 0)return 0;
    const auto pos = num + offset;
    if (visited[pos])return memo[pos];
    visited[pos] = 1;
    return memo[pos] = (GO2(num - 1) + GO2(num - 2)) % MOD;
}
void Solve() noexcept
{
    int n; cin >> n;
    const auto res = n < 0 ? GO1(n) : GO2(n);
    if (res > 0)cout << 1;
    else if (res < 0)cout << -1;
    else cout << 0;
    cout << '\n' << abs(res);
}
int main()
{
    FastIO();
    Solve();
}