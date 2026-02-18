#include <bits/stdc++.h>
using namespace std;
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
map<int, vector<int>> adj;
int n, k;
int arr[1001];
map<int, vector<int>> m_level;
map<int, int> level_map;
map<int, int> parents;
void dfs(const int cur, const int cur_level)
{
    m_level[cur_level].emplace_back(cur);
    level_map[cur] = cur_level;
    for (const auto next : adj[cur])
    {
        parents[next] = cur;
        dfs(next, cur_level + 1);
    }
}
void Solve()noexcept
{
    for (;;)
    {
        cin >> n >> k;
        if (n == 0 && k == 0)break;
        queue<int> pq;
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        adj.clear();
        level_map.clear();
        m_level.clear();
        parents.clear();
        pq.emplace(arr[0]);
        if (n <= 1)
        {
            cout << 0 << '\n';
            continue;
        }
        int prev = arr[1] - 1;
        int cur_parent = pq.front();
        for (int i = 1; i < n; ++i)
        {
            if (arr[i] != prev + 1)
            {
                pq.pop();
                cur_parent = pq.front();
            }
            adj[cur_parent].emplace_back(arr[i]);
            prev = arr[i];
            pq.emplace(arr[i]);
        }
        dfs(arr[0], 0);
        if (k == arr[0])
        {
            cout << 0 << '\n';
            continue;
        }
        const auto cur_level = level_map[k];
        const auto p = parents[k];
        int ans = 0;
        for (const auto i : m_level[cur_level])
        {
            if (p == parents[i])continue;
            const auto p1 = parents[p];
            const auto p2 = parents[parents[i]];
            ans += p1 == p2;
        }
        cout << ans << '\n';
    }
}
int main()
{
    FastIO();
    Solve();
}
