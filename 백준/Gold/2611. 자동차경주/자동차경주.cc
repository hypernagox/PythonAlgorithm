#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
vector<pi> adj[1001];
int n, m;
bool flag;
int path[1001];
int memo[1001];
int GO(const int cur)
{
    if (flag && cur == 1)
    {
        return 0;
    }
    auto& ref = memo[cur];
    if (~ref)return ref;
    flag = true;
    int res = 0;
    int next_node = 0;
    for (const auto [next, cost] : adj[cur])
    {
        const auto val = GO(next) + cost;
        if (res < val)
        {
            res = val;
            next_node = next;
        }
    }
    path[cur] = next_node;
    return ref = res;
}
void PrintPath(const int cur)
{
    if (flag && 1 == cur)
    {
        cout << cur << ' ';
        return;
    }
    flag = true;
    cout << cur << ' ';
    PrintPath(path[cur]);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    while (m--)
    {
        int p, q, c; cin >> p >> q >> c;
        adj[p].emplace_back(q, c);
    }
    memset(memo, -1, sizeof(memo));
    cout << GO(1) << '\n';
    flag = false;
    PrintPath(1);
}