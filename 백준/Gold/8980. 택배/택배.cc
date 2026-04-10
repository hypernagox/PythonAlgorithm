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
struct Data
{
    int from;
    int to;
    int cap;
    const auto operator<(const Data& d)const {
        return to < d.to;
    }
};
void Solve() noexcept
{
    int n, c, k; cin >> n >> c >> k;
    vector<Data> items; items.reserve(k);
    vector<int> capitices(n, c); // i번 마을에서의 남은 용량
    for (int i = 0; i < k; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        items.emplace_back(a - 1, b - 1, c);
    }
    sort(items.begin(), items.end());
    int ans = 0;
    for (const auto [from, to, cap] : items)
    {
        int can_keep = min(c, cap);
        for (int i = from; i < to; ++i)
        {
            can_keep = min(can_keep, capitices[i]);
        }
        ans += can_keep;
        for (int i = from; i < to; ++i)
        {
            capitices[i] -= can_keep;
        }
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}