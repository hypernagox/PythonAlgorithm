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
constexpr const ll MOD = 1000000009;
ll memo[1000001];
// GO(cur) = GO(cur-1) + GO(cur-2) + GO(cur-3)
ll GO(const ll cur)
{
    if (cur < 0)return 0;
    if (cur == 0)return 1;
    auto& ref = memo[cur];
    if (~ref)return ref;
    const auto a = GO(cur - 1) % MOD;
    const auto b = GO(cur - 2) % MOD;
    const auto c = GO(cur - 3) % MOD;
    return ref = (a + b + c) % MOD;
}
void Solve() noexcept
{
    int t; cin >> t;
    memset(memo, -1, sizeof(memo));
    while (t--)
    {
        int n; cin >> n;
        cout << GO(n) << '\n';
    }
}
int main()
{
    FastIO();
    Solve();
}