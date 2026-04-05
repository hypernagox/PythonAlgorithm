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
int arr[10001];
int memo[20][10001];
int n;
int GO(const int start, const int cur)
{
    if (cur < 0)return 0;
    if (cur == 0)return 1;
    auto& ref = memo[start][cur];
    if (~ref)return ref;
    int res = 0;
    for (int i = start; i < n; ++i) res += GO(i, cur - arr[i]);
    return ref = res;
}
void Solve() noexcept
{
    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)cin >> arr[i];
        int coin; cin >> coin;
        memset(memo, -1, sizeof(memo));
        cout << GO(0, coin) << '\n';
    }
}
int main()
{
    FastIO();
    Solve();
}