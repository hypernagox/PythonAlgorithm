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
ll dists[10001];
vector<pll> adj[10001];
bool visited[10001];
int n, m;
void Solve()noexcept
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        adj[a].emplace_back(c, b);
        adj[b].emplace_back(c, a);
    }
    int start, end; cin >> start >> end;
    priority_queue<pll> pq;
    pq.emplace(INT64_MAX, start);
    while (pq.size())
    {
        const auto [cost, cur] = pq.top();
        pq.pop();
        if (visited[cur])continue;
        visited[cur] = 1;
        if (cur == end)
        {
            cout << cost;
            break;
        }
        for (const auto [c, next] : adj[cur])
        {
            const auto new_cost = min(c, cost);
            if (visited[next])continue;
            if (dists[next] > new_cost)continue;
            dists[next] = new_cost;
            pq.emplace(new_cost, next);
        }
    }
}
int main()
{
    FastIO();
    Solve();
}