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
int n, k;
int arr[101];
int memo[101][10001];
int GO(const int idx, const int cur_money)
{
    if (cur_money < 0)return INF;
    if (cur_money == 0)return 0;
    if (idx == n)return cur_money == 0 ? 0 : INF;
    auto& ref = memo[idx][cur_money];
    if (~ref)return ref;
    // 사용
    const auto a = GO(idx, cur_money - arr[idx]) + 1;
    // 안사용
    const auto b = GO(idx + 1, cur_money);
    return ref = min(a, b);
}
void Solve() noexcept
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)cin >> arr[i];
    memset(memo, -1, sizeof(memo));
    const auto ans = GO(0, k);
    if (ans >= INF)cout << -1;
    else cout << ans;
}
int main()
{
    FastIO();
    Solve();
}