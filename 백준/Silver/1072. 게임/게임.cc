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
ll GetPercent(const ll x, const ll y)
{
    return (y * 100.) / x;
}
void Solve() noexcept
{
    ull x, y; cin >> x >> y;
    const auto z = GetPercent(x, y);
    ull l = 1;
    ull r = 2000000000ULL;
    ll ans = -1;
    while (l < r)
    {
        const auto mid = (l + r) / 2LL;
        const auto val = GetPercent(x + mid, y + mid);
        if (val > z)
        {
            ans = mid;
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}