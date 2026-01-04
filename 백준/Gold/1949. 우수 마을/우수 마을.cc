#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
vector<int> adj[10001];
int humans[10001];
int n;
int memo[10001][2];
bool visited[10001];
int GO(const int cur, const bool selected)
{
    auto& ref = memo[cur][selected];
    if (-1 != ref)return ref;
    visited[cur] = true;
    int res = humans[cur];
    // 만약 cur 가 선택됐다면
    if (selected)
    {
        for (const auto next : adj[cur])
        {
            if (visited[next])continue;
            // next는 선택 할 수 없다.
            res += GO(next, false);
        }
    }
    else
    {
        res = 0;
        for (const auto next : adj[cur])
        {
            if (visited[next])continue;
            // 이렇게해도 최대값을 구하는 것이기 때문에 누군가는 선택될 것이다.
            res += max(GO(next, true), GO(next, false));
        }
    }
    visited[cur] = false;
    return ref = res;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> humans[i + 1];
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b; cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    memset(memo, -1, sizeof(memo));
    const auto a = GO(1, 0);
    const auto b = GO(1, 1);
    cout << max(a, b);
}