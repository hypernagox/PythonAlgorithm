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
vector<pi> adj[300001];
int subtrees[300001];
ll memo[300001];
int n;
void GetSub(const int cur, const int prev)
{
    for (const auto [c, next] : adj[cur])
    {
        if (prev == next)continue;
        ++subtrees[cur];
        GetSub(next, cur);
        subtrees[cur] += subtrees[next];
        memo[cur] += memo[next] + (subtrees[next] + 1) * c;
    }
}
void GO(const int cur, const int prev)
{
    for (const auto [c, next] : adj[cur])
    {
        if (prev == next)continue;
        memo[next] = memo[cur] - ((subtrees[next] + 1) * c) + ((n - subtrees[next] - 1) * c);
        GO(next, cur);
    }
}
void Solve()noexcept
{
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        adj[a].emplace_back(c, b);
        adj[b].emplace_back(c, a);
    }
    GetSub(1, 0);
    GO(1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cout << memo[i] << '\n';
    }
}
int main()
{
    FastIO();
    Solve();
}