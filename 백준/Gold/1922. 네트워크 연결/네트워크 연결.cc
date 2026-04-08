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
bool visited[1001];
int dists[1001];
vector<pi> adj[1001];
void Solve() noexcept
{
    int n, m; cin >> n >> m;
    while (m--)
    {
        int a, b, c; cin >> a >> b >> c;
        adj[a].emplace_back(c, b);
        adj[b].emplace_back(c, a);
    }
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    fill(dists, dists + sizeof(dists) / 4, INF);
    pq.emplace(0, 1);
    dists[1] = 0;
    ll ans = 0;
    while (pq.size())
    {
        const auto [cost, cur] = pq.top();
        pq.pop();
        if (visited[cur])continue;
        visited[cur] = 1;
        ans += cost;
        for (const auto [c, next] : adj[cur])
        {
            if (visited[next])continue;
            if (dists[next] <= c)continue;
            dists[next] = c;
            pq.emplace(c, next);
        }
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}