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
vector<int> adj[1000001];
int visited[1000001];
void GO(const int cur, const int num)
{
    visited[cur] = num;
    for (const auto next : adj[cur])
    {
        if (visited[next])continue;
        GO(next, num);
    }
}
void Solve() noexcept
{
    int t; cin >> t;
    string str = "Scenario 0:\n";
    int cnt = 1;
    while (t--)
    {
        int n, k; cin >> n >> k;
        while (k--)
        {
            int a, b; cin >> a >> b;
            adj[a].emplace_back(b);
            adj[b].emplace_back(a);
        }
        int m; cin >> m;
        for (int i = 0; i < n; ++i)
        {
            if (visited[i])continue;
            GO(i, i + 1);
        }
        *next(++str.rbegin()) = (cnt++) + '0';
        cout << str;
        while (m--)
        {
            int a, b; cin >> a >> b;
            cout << (visited[a] == visited[b]) << '\n';
        }
        cout << '\n';   
        ranges::for_each(adj, adj + n, &vector<int>::clear);
        memset(visited, 0, sizeof(visited));
    }
}
int main()
{
    FastIO();
    Solve();
}