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
    int t; cin >> t;
    while (t--)
    {
        ull n; cin >> n;
        ull l = 1;
        ull r = n;
        ull ans = 1;
        while (l < r)
        {
            const auto mid = (l + r) / 2LL;
            const auto val = (mid) * (mid + 1LL) / 2LL;
            if (val <= n)
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        cout << ans << '\n';
    }
}
int main()
{
    FastIO();
    Solve();
}