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
ll arr[21];
ll n, m;
ll ans;
void GO(const int start, ll s, const int cnt, const int dest)
{
    if (dest == cnt)
    {
        ans += s == m;
        return;
    }
    for (int i = start; i < n; ++i)
    {
        GO(i + 1, s + arr[i], cnt + 1, dest);
    }
}
void Solve() noexcept
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)cin >> arr[i];
    for (int i = 1; i <= n; ++i)
    {
        GO(0, 0, 0, i);
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}