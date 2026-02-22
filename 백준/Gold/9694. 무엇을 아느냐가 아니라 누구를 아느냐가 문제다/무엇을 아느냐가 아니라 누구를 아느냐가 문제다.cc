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
map<int, int> parents;
vector<int> ans;
void Solve()noexcept
{
    int t; cin >> t;
    int cnt = 1;
    while (t--)
    {
        vector<pi> adj[21];
        int dists[21];
        fill(dists, dists + 21, INF);
        int n, m; cin >> n >> m;
        for (int i = 0; i < n; ++i)
        {
            int a, b, c; cin >> a >> b >> c;
            adj[a].emplace_back(c, b);
            adj[b].emplace_back(c, a);
        }
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.emplace(0, 0);
        dists[0] = 0;
        parents[0] = 0;
        while (pq.size())
        {
            const auto [cost, cur] = pq.top();
            pq.pop();
            if (dists[cur] < cost)continue;
            if (cur == m - 1)
            {
                int now = cur;
                while (now)
                {
                    ans.emplace_back(now);
                    now = parents[now];
                }
                ans.emplace_back(0);
                reverse(ans.begin(), ans.end());
                break;
            }
            for (const auto [c, next] : adj[cur])
            {
                const auto new_cost = c + cost;
                if (dists[next] < new_cost)continue;
                dists[next] = new_cost;
                pq.emplace(new_cost, next);
                parents[next] = cur;
            }
        }
        cout << "Case #" << cnt++ << ": ";
        if (ans.empty())cout << -1;
        else for (const auto i : ans)cout << i << ' ';
        cout << '\n';
        ans.clear();
    }
}
int main()
{
    FastIO();
    Solve();
}