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
struct Edge
{
    int from;
    int to;
    int cost;
    const auto operator<(const Edge& e)const {
        return cost < e.cost;
    }
};
vector<int> parents;
int FindParent(const int cur)
{
    auto& parent = parents[cur];
    return parent = parent == cur ? cur : FindParent(parent);
}
bool Union(int a, int b)
{
    a = FindParent(a);
    b = FindParent(b);
    if (a == b)return false;
    if (a > b)swap(a, b);
    parents[b] = a;
    return true;
}
void Solve() noexcept
{
    int n, m; cin >> n >> m;
    parents.resize(n + 1);
    iota(parents.begin(), parents.end(), 0);
    vector<Edge> edges; edges.reserve(m);
    while (m--)
    {
        int a, b, c; cin >> a >> b >> c;
        edges.emplace_back(a, b, c);
    }
    sort(edges.begin(), edges.end());
    ll ans = 0;
    for (const auto [from, to, cost] : edges)
    {
        if (Union(from, to))
        {
            ans += cost;
        }
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}