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
vector<pi> adj[251];
int dists[251][251];
void Solve() noexcept
{
    int n, m; cin >> n >> m;
    while (m--)
    {
        int a, b, c; cin >> a >> b >> c;
        adj[a].emplace_back(0, b);
        adj[b].emplace_back(!c, a);
    }
    for (int i = 1; i <= n; ++i)
    {
        fill(dists[i], dists[i] + n + 1, INF);
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        pq.emplace(0, i);
        dists[i][i] = 0;
        while (!pq.empty())
        {
            const auto [cost, cur] = pq.top();
            pq.pop();
            if (dists[i][cur] < cost)continue;
            for (const auto [c, next] : adj[cur])
            {
                const auto new_cost = c + cost;
                if (dists[i][next] > new_cost)
                {
                    dists[i][next] = new_cost;
                    pq.emplace(new_cost, next);
                }
            }
        }
    }
    int t; cin >> t;
    while (t--)
    {
        int a, b; cin >> a >> b;
        cout << dists[a][b] << '\n';
    }
}
int main()
{
    FastIO();
    Solve();
}