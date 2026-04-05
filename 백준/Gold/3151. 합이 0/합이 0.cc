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
    int n; cin >> n;
    vector<int> v; v.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        v.emplace_back(x);
    }
    ranges::sort(v.begin(), v.end());
    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        const auto a = v[i];
        for (int j = i + 1; j < n; ++j)
        {
            const auto b = v[j];
            const auto target = -(a + b);
            const auto iter = ranges::lower_bound(v.begin() + j + 1, v.end(), target);
            const auto iter2 = ranges::upper_bound(v.begin() + j + 1, v.end(), target);
            if (v.end() != iter && *iter == target)
            {
                ans += (iter2 - iter);
            }
        }
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}