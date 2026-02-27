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
vector<int> adj[10001];
int costs[10001];
bool visited[10001];
int n, m;
int lim;
int GO(const int cur)
{
    visited[cur] = 1;
    int cur_cost = costs[cur];
    for (const auto next : adj[cur])
    {
        if (visited[next])continue;
        cur_cost = min(cur_cost, GO(next));
    }
    return cur_cost;
}
void Solve()noexcept
{
    cin >> n >> m >> lim;
    for (int i = 0; i < n; ++i)
    {
        cin >> costs[i + 1];
    }
    for (int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    int min_cost = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (visited[i])continue;
        min_cost += GO(i);
    }
    if (lim >= min_cost)cout << min_cost;
    else cout << "Oh no";
}
int main()
{
    FastIO();
    Solve();
}
