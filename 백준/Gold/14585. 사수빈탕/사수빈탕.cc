#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
constexpr const int dy[]{ 1,0 };
constexpr const int dx[]{ 0,1 };
bool visited[301][301];
ll candy[301][301];
ll memo[301][301];
ll GO(const int y, const int x, const int times)
{
    visited[y][x] = 1;
    if (times == m)return 0;
    auto& ref = memo[y][x];
    if (~ref)return ref;
    ll res = 0;
    for (int i = 0; i < 2; ++i)
    {
        const auto ny = y + dy[i];
        const auto nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= 300 || nx >= 300)continue;
        if (visited[ny][nx])continue;
        res = max(res,GO(ny, nx, times + 1));
    }
    visited[y][x] = 0;
    return ref = res + max(0LL, ll(candy[y][x] - times));
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        int a, b; cin >> a >> b;
        candy[b][a] = m;
    }
    memset(memo, -1, sizeof(memo));
    cout << GO(0, 0, 0);
}