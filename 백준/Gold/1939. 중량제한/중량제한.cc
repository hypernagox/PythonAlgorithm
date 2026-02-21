#include <bits/stdc++.h>
using namespace std;
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
constexpr const int INF = 987654321;
constexpr const int MIN_INF = -INF;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
ll dists[10001];
vector<pll> adj[10001];
bool visited[10001];
int n, m;
struct Data
{
    int cur;
    ll cost;
    ll ans;
    const auto operator <(const Data& d)const {
        return cost < d.cost;
    }
};
void Solve()noexcept
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        adj[a].emplace_back(c, b);
        adj[b].emplace_back(c, a);
    }
    int start, end; cin >> start >> end;
    priority_queue<Data> pq;
    pq.emplace(start,0LL,INT64_MAX);
    //visited[start] = 1;
    set<ll>s;
    while (pq.size())
    {
        const auto [cur,cost,ans] = pq.top();
        pq.pop();
        if (visited[cur])continue;
        visited[cur] = 1;
        if (cur == end)
        {
            cout << ans;
            break;
        }
        for (const auto [c, next] : adj[cur])
        {
            const auto new_cost = c;
            if (dists[next] > new_cost)continue;
            dists[next] = new_cost;
            pq.emplace(next, new_cost, min(ans, c));
        }
    }
   // cout << *s.rbegin();
}
int main()
{
    FastIO();
    Solve();
}