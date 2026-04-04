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
    int amount;
    const auto operator<(const Data& d)const {
        if (to == d.to)return from < d.from;
        return to < d.to;
    }
};
Data items[2001];
int capacities[2001];
void Solve() noexcept
{
    int n, c, m; cin >> n >> c >> m;
    fill(capacities, capacities + n, c);
    for (int i = 0; i < m; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        items[i] = Data{ a - 1,b - 1,c };
    }
    sort(items, items + m);
    int ans = 0;
    for (int i = 0; i < m; ++i)
    {
        const auto [from, to, amount] = items[i];
        const auto remain_cap = *min_element(capacities + from, capacities + to);
        const auto delta = min(amount, remain_cap);
        ans += delta;
        for (int j = from; j < to; ++j)capacities[j] -= delta;
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}