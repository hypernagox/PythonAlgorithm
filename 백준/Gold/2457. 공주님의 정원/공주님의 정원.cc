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
    vector<pi> v;
    for (int i = 0; i < n; ++i)
    {
        int a, b, c, d; cin >> a >> b >> c >> d;
        v.emplace_back(a * 100 + b, c * 100 + d);
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    int cur_start = 301;
    int max_end = 0;
    for (int i = 0; i < n; ++i)
    {
        const auto [start, end] = v[i];
        if (start <= cur_start)
        {
            max_end = max(max_end, end);
        }
        else
        {
            --i;
            if (cur_start == max_end)break;
            cur_start = max_end;
            ++cnt;
        }
        if (max_end >= 1201)
        {
            ++cnt;
            cout << cnt;
            return;
            break;
        }
    }
    cout << 0;
}
int main()
{
    FastIO();
    Solve();
}