#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
int n;
vector<int> tree[1000001];
bool visited[1000001];
int memo[1000001][2];
int GO(const int cur_node, const bool selected)
{
    auto& ref = memo[cur_node][selected];
    if (~ref)return ref;
    visited[cur_node] = true;
    int res = 0;
    // 이 노드가 선택 안되었다면
    if (!selected)
    {
        // 자식 노드들은 전부 얼리어답터여야함
        for (const auto next : tree[cur_node])
        {
            if (visited[next])continue;
            res += GO(next, true);
        }
    }
    else
    {
        // 이 노드가 선택 되었다면 일수도 아닐수도
        for (const auto next : tree[cur_node])
        {
            if (visited[next])continue;
            // 자식 노드는 선택 할 수도 있고 안 할 수도 있음
            res += min(GO(next, true), GO(next, false));
        }
    }
    visited[cur_node] = false;
    return ref = res + selected;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b; cin >> a >> b;
        tree[a].emplace_back(b);
        tree[b].emplace_back(a);
    }
    memset(memo, -1, sizeof(memo));
    cout << min(GO(1, 0), GO(1, 1));
}