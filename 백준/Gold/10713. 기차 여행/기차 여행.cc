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
ll edge_use[100005];
int n, m;
int dests[100005];
void Solve()noexcept
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> dests[i];
    }
    for (int i = 0; i < m - 1; ++i)
    {
        int a = dests[i];
        int b = dests[i + 1];
        if (a > b) swap(a, b);
        edge_use[a]++;
        edge_use[b]--;
    }
    for (int i = 1; i <= n; ++i)
    {
        edge_use[i] += edge_use[i - 1];
    }
    ll ans = 0;
    for (int i = 1; i <= n - 1; ++i)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        const ll x = edge_use[i] * a;
        const ll y = edge_use[i] * b + c;
        ans += min(x, y);
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}