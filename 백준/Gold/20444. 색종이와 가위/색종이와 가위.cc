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
void Solve() noexcept
{
    // (a+1) * (b+1)
    // a + b = n
    // b = n - a
    ll n, k; cin >> n >> k;
    ll l = 0;
    ll r = n;
    ll ans = 0;
    while (l < r)
    {
        const auto mid = (l + r) / 2LL;
        const auto val = (mid + 1) * (n - mid + 1);
        if (val >= k)
        {
            ans = mid;
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    if ((ans + 1) * (n - ans + 1) == k)cout << "YES";
    else cout << "NO";
}
int main()
{
    FastIO();
    Solve();
}