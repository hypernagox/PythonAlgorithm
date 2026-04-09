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
vector<pi> adj[101];
int n, m;
int inDegree[101];
int memo[101];
int GO(const int cur)
{
    if (adj[cur].empty())return 1;
    auto& ref = memo[cur];
    if (ref)return ref;
    int res = 0;
    for (const auto [c, next] : adj[cur])
    {
        res += GO(next) * c;
    }
    return ref = res;
}

void Solve() noexcept
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        adj[b].emplace_back(c, a);
        ++inDegree[a];
    }
    vector<int> base;
    for (int i = 1; i <= n; ++i)
    {
        if (inDegree[i] == 0)
        {
            base.emplace_back(i);
        }
    }
    for (const auto i : base)
    {
        cout << i << ' ' << GO(i) << '\n';
    }
}
int main()
{
    FastIO();
    Solve();
}