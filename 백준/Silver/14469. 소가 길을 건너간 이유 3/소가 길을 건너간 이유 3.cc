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
        int a, b; cin >> a >> b;
        v.emplace_back(a, b);
    }
    sort(v.begin(), v.end());
    int cur_last = 0;
    for (const auto [start, wait] : v)
    {
        cur_last = max(cur_last, start) + wait;
    }
    cout << cur_last;
}
int main()
{
    FastIO();
    Solve();
}