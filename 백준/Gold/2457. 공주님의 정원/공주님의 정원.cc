#include <bits/stdc++.h>
using namespace std;
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
constexpr const int INF = static_cast<int>(1e9) + 1;
constexpr const int MIN_INF = -INF;
using ll = long long;
using ull = unsigned long long;
using pi = pair<short, short>;
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
    ranges::sort(v.begin(), v.end());
    int ans = 0;
    short cur_end = 301;
    auto start = v.begin();
    const auto END = v.end();
    for (;;)
    {
        if (cur_end >= 1201)break;
        const auto iter = ranges::upper_bound(start, END, make_pair(cur_end, (short)1231));
        short max_end = -1;
        for (auto it = start; it < iter; ++it)
        {
            max_end = max(max_end, it->second);
        }
        if (cur_end == max_end || max_end == -1)
        {
            cout << 0;
            return;
        }
        start = iter;
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