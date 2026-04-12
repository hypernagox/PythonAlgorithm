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
int w[101];
int v[101];
int n, k;
int memo[101][100001];
int GO(const int idx, const int cap)
{
    if (cap < 0)return -INF;
    if (cap == 0)return 0;
    if (idx == n)return cap < 0 ? -INF : 0;
    auto& ref = memo[idx][cap];
    if (~ref)return ref;
    return ref = max(GO(idx + 1, cap - w[idx]) + v[idx],
               GO(idx + 1, cap));
}
void Solve() noexcept
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)cin >> w[i] >> v[i];
    memset(memo, -1, sizeof(memo));
    cout << GO(0, k);
}
int main()
{
    FastIO();
    Solve();
}