#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
vector<int> tree[10001];
int costs[10001];
bool visited[10001];
int n;
int memo[10001][2];
vector<int> v;
int GO(const int cur_node,const bool flag)
{
    auto& ref = memo[cur_node][flag];
    if (-1 != ref)return ref;
    visited[cur_node] = true;
    int res = 0;
    // 이 정점을 선택했다면 다음 정점은 선택 못함
    if (flag)
    {
        for (const auto next : tree[cur_node])
        {
            if (visited[next])continue;
            res += GO(next, false);
        }
    }
    // 이번 정점을 선택하지 않았으면 다음정점은 맘대로
    else
    {
        int val = 0;
        for (const auto next : tree[cur_node])
        {
            if (visited[next])continue;
            const auto a = GO(next, true);
            const auto b = GO(next, false); // 전부 선택하지않아도 누군가는 인접할예정
            res += max(a, b);
        }
    }
    visited[cur_node] = false;
    return ref = res + costs[cur_node] * flag;
}
void Trace(const int cur,const bool selected)
{
    visited[cur] = true;
    bool f = false;
    if (!selected && memo[cur][0] < memo[cur][1])
    {
        f = true;
        v.emplace_back(cur);
    }
    for (const auto next : tree[cur])
    {
        if (visited[next])continue;
        Trace(next, f);
    } 
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> costs[i + 1];
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b; cin >> a >> b;
        tree[a].emplace_back(b);
        tree[b].emplace_back(a);
    }
    memset(memo, -1, sizeof(memo));
    cout << max(GO(1, 0), GO(1, 1)) << '\n';
    Trace(1, 0);
    sort(v.begin(), v.end());
    for (const auto i : v)cout << i << ' ';
}