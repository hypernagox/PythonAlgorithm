#include <iostream>
#include <algorithm>
#include <ranges>
#include <vector>
#include <queue>
using namespace std;
vector<int> adj[1001];
int costs[1001];
int inDegree[1001];
int res[1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t, n, k; cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) { cin >> costs[i]; inDegree[i] = 0; res[i] = costs[i]; adj[i].clear(); }
        while (k--) {
            int a, b; cin >> a >> b;
            adj[a].emplace_back(b);
            ++inDegree[b];
        }
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (!inDegree[i])q.emplace(i);
        }
        int dest; cin >> dest;
        while (!q.empty()) {
            const auto node = q.front(); q.pop();
            for (const auto i : adj[node]) {
                if (0 == --inDegree[i])q.emplace(i);
                res[i] = max(res[i], res[node] + costs[i]);
            }
        }
        cout << res[dest] << '\n';
    }
}