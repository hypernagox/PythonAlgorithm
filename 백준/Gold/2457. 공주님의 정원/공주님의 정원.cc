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
    vector<pi> v; v.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int a, b, c, d; cin >> a >> b >> c >> d;
        v.emplace_back(a * 100 + b, c * 100 + d);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int cur_end = 301;
    for (;;)
    {
        if (cur_end >= 1201)break;
        const auto iter = upper_bound(v.begin(), v.end(), make_pair(cur_end, INF));
        int max_end = -1;
        for (auto it = v.begin(); it < iter; ++it)
        {
            max_end = max(max_end, it->second);
        }
        if (cur_end == max_end ||max_end == -1)
        {
            cout << 0;
            return;
        }
        ++ans;
        cur_end = max_end;
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}