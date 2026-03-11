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
vector<int> adj[101];
int visited[101];
int b, e;
void GO(const int cur)
{
    for (const auto next : adj[cur])
    {
        if (visited[next])continue;
        visited[next] = visited[cur] + 1;
        GO(next);
    }
}
void Solve()noexcept
{
    int n; cin >> n >> b >> e;
    int k; cin >> k;
    while (k--)
    {
        int a, b; cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    visited[b] = 1;
    GO(b);
    cout << visited[e] - 1;
}
int main()
{
    FastIO();
    Solve();
}