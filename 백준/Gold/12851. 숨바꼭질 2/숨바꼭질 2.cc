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
int visited[100001];
void Solve() noexcept
{
    int src, dest; cin >> src >> dest;
    queue<pi> q;
    fill(visited, visited + sizeof(visited) / sizeof(int), INF);
    visited[src] = 0;
    q.emplace(src, 0);
    int ans = 0;
    while (q.size())
    {
        const auto [cur, cost] = q.front();
        q.pop();
        if (cur < 0 || cur >100000)continue;
        if (visited[cur] < cost)continue;
        visited[cur] = cost;
        if (cur == dest)
        {
            ++ans;
            continue;
        }
        q.emplace(cur + 1, cost + 1);
        q.emplace(cur - 1, cost + 1);
        q.emplace(cur * 2, cost + 1);
    }
    cout << visited[dest] << '\n' << ans;
}
int main()
{
    FastIO();
    Solve();
}