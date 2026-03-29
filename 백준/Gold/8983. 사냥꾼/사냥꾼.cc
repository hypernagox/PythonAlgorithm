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
ll n, m, l;
pll GetRange(const pll p)
{
    const auto [x, y] = p;
    const auto d = l - y;
    return { x - d,x + d };
}
void Solve() noexcept
{
    cin >> m >> n >> l;
    vector<ll> pos; pos.reserve(m);
    vector<pll> animals; animals.reserve(n);
    for (int i = 0; i < m; ++i)
    {
        ll x; cin >> x;
        pos.emplace_back(x);
    }
    for (int i = 0; i < n; ++i)
    {
        ll x, y; cin >> x >> y;
        if (y > l)continue;
        animals.emplace_back(x, y);
    }
    sort(pos.begin(), pos.end());
    ll res = 0;
    for (int i = 0; i < animals.size(); ++i)
    {
        const auto [x1, x2] = GetRange(animals[i]); // x1이상 x2이하가 있나?
        const auto iter = lower_bound(pos.begin(), pos.end(), x1);
        if (pos.end() != iter && *iter <= x2)
        {
            ++res;
        }
    }
    cout << res;
}
int main()
{
    FastIO();
    Solve();
}