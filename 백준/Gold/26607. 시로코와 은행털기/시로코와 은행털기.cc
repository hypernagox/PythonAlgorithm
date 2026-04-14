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
int power[81];
int speed[81];
int n, k, x;
int memo[81][16001][81];
int GO(const int idx, const int p, const int cur)
{
    if (cur < 0)return -INF;
    if (cur == 0) return p * ((k * x) - p);
    if (idx == n)return cur == 0 ? p * ((k * x) - p) : -INF;
    auto& ref = memo[idx][p][cur];
    if (~ref)return ref;
    return ref = max(GO(idx + 1, p + power[idx], cur - 1),
        GO(idx + 1, p, cur));
}
void Solve() noexcept
{
    cin >> n >> k >> x;
    for (int i = 0; i < n; ++i)cin >> power[i] >> speed[i];
    memset(memo, -1, sizeof(memo));
    cout << GO(0, 0, k);
}
int main()
{
    FastIO();
    Solve();
}