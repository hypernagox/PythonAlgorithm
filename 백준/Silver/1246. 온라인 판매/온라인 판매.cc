#include <bits/stdc++.h>
using namespace std;
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
constexpr const int INF = 987654321;
constexpr const int MIN_INF = -INF;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
void Solve()noexcept
{
    int n, m; cin >> n >> m;
    vector<int> values; values.reserve(m);
    for (int i = 0; i < m; ++i)
    {
        int x; cin >> x;
        values.emplace_back(x);
    }
    sort(values.begin(), values.end());
    int ans = 0;
    int res = 0;
    for (int i = 0; i < m; ++i)
    {
        const auto cand = values[i] * min(n, m - i);
        if (ans < cand)
        {
            ans = cand;
            res = values[i];
        }
    }
    cout << res << ' ' << ans;
}
int main()
{
    FastIO();
    Solve();
}