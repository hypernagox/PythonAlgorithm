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
int n, m, k;
vector<pll> adj[100001]; // a번 도시에 연결된 {간선,비용} map
ll dists[100001]; // a번 도시에서 면접장까지의 최단거리
void Solve()noexcept
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        adj[b].emplace_back(a, c);
    }
    fill(begin(dists), end(dists), INT64_MAX / 2);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    for (int i = 0; i < k; ++i)
    {
        int a; cin >> a;
        dists[a] = 0;
        pq.emplace(0, a);
    }
    while (pq.size())
    {
        const auto [cost, cur] = pq.top();
        pq.pop();
        if (dists[cur] < cost)continue;
        for (const auto [next, c] : adj[cur])
        {
            const auto new_cost = (ll)cost + (ll)c;
            // next도시의 면접장까지의 최단거리
            if (dists[next] > new_cost)
            {
                dists[next] = new_cost;
                pq.emplace(new_cost, next);
            }
        }
    }
    ll max_dist = 0;
    int idx = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (max_dist < dists[i])
        {
            max_dist = dists[i];
            idx = i;
        }
    }
    cout << idx << '\n' << max_dist;
}
int main()
{
    FastIO();
    Solve();
}