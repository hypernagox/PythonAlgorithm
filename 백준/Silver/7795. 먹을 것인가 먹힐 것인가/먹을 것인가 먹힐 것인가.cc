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
        int a, b; cin >> a >> b;
        vector<int> v1, v2;
        while (a--)
        {
            int x; cin >> x;
            v1.emplace_back(x);
        }
        while (b--)
        {
            int x; cin >> x;
            v2.emplace_back(x);
        }
        sort(v2.begin(), v2.end());
        ll ans = 0;
        const auto bb = v2.begin();
        for (const auto i : v1)
        {
            ans += lower_bound(v2.begin(), v2.end(), i) - bb;
        }
        cout << ans << '\n';
    }
}
int main()
{
    FastIO();
    Solve();
}