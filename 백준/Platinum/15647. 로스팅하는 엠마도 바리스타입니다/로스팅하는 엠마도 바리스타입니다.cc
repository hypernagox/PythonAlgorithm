#include <bits/stdc++.h>
using namespace std;
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
constexpr const int INF = static_cast<int>(1e9);
constexpr const int MIN_INF = -INF;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
int sub_trees[300001];
vector<pi> trees[300001];
int n;
ll dists[300001];
void CalSub(const int cur, const int prev)
{
    ++sub_trees[cur];
    for (const auto [c, next] : trees[cur])
    {
        if (next == prev)continue;
        CalSub(next, cur);
        sub_trees[cur] += sub_trees[next];
        dists[1] += (sub_trees[next] * c);
    }
}
void GO(const int cur, const int prev)
{
    for (const auto [c, next] : trees[cur])
    {
        if (next == prev)continue;
        dists[next] = dists[cur] - (c * sub_trees[next]) + ((n - sub_trees[next]) * c);
        GO(next, cur);
    }
}
void Solve()noexcept
{
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        trees[a].emplace_back(c, b);
        trees[b].emplace_back(c, a);
    }
    CalSub(1, 0);
    GO(1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cout << dists[i] << ' ';
    }
}
int main()
{
    FastIO();
    Solve();
}