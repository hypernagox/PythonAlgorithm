#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
int inDegree[101];
vector<pi> adj[101];
int res[101][101];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<int> ans;
    queue<int> q;
    while (m--)
    {
        int a, b, c; cin >> a >> b >> c;
        adj[b].emplace_back(c, a);
        ++inDegree[a];
    }
    for (int i = 0; i < n; ++i)
    {
        if (0 == inDegree[i + 1])
        {
            q.emplace(i + 1);
            ans.emplace_back(i + 1);
            res[i + 1][i + 1] = 1;
        }
    }
    while (!q.empty())
    {
        const auto cur = q.front();
        q.pop();
        for (const auto [cost, next] : adj[cur])
        {
            for (int b = 1; b <= n; ++b)
            {
                if (res[cur][b] != 0)
                {
                    res[next][b] += res[cur][b] * (ll)cost;
                }
            }
            if (0 == --inDegree[next])
            {
                q.emplace(next);
            }
        }
    }
    for (const auto i : ans)cout << i << ' ' << res[n][i] << '\n';
}