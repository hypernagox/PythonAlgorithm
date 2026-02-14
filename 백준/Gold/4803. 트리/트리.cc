#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
bool dfs(int state[], vector<short> adj[], const short cur_node, const short parent_node)
{
    if (0 != state[cur_node])
    {
        return false;
    }
    bool ret = true;
    state[cur_node] = 1;
    for (const auto next : adj[cur_node])
    {
        if (next == parent_node)continue;
        ret &= dfs(state, adj, next, cur_node);
    }
    state[cur_node] = 2;
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int cnt = 0;
    for (;;)
    {
        int n, m; cin >> n >> m;
        int ans = 0;
        if (0 == n)break;
        int state[501]{};
        vector<short> adj[501];
        while (m--)
        {
            int a, b; cin >> a >> b;
            adj[a].emplace_back(b);
            adj[b].emplace_back(a);
        }
        for (int i = 1; i <= n; ++i)
        {
            if (state[i])continue;
            ans += dfs(state, adj, i, -1);
        }
        cout << "Case " << ++cnt << ": ";
        if (0 == ans)
        {
            cout << "No trees.\n";
        }
        else if (1 == ans)
        {
            cout << "There is one tree.\n";
        }
        else
        {
            cout << "A forest of " << ans << " trees.\n";
        }
    }
}