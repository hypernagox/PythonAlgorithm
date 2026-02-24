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
constexpr const int dy[]{ -1,0,1,0 };
constexpr const int dx[]{ 0,1,0,-1 };
int board[101][101];
int n, m, k;
bool visited[101][101];
vector<vector<pi>> clusters;
vector<pi> cluster;
bool CanGo(const int y, const int x)
{
    if (y < 0 || x < 0 || y >= n || x >= n)return false;
    if (visited[y][x])return false;
    if (board[y][x])return false;
    return true;
}
void GO(const int y, const int x)
{
    visited[y][x] = 1;
    cluster.emplace_back(y, x);
    for (int i = 0; i < 4; ++i)
    {
        const auto ny = y + dy[i];
        const auto nx = x + dx[i];
        if (!CanGo(ny, nx))continue;
        GO(ny, nx);
    }
}
void Solve()noexcept
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!CanGo(i,j))continue;
            GO(i, j);
            clusters.emplace_back(move(cluster));
        }
    }
    int need = 0;
    for (const auto& c : clusters)
    {
        need += ((int)c.size() + k - 1) / k;
    }
    const auto ans = m - need;
    if (ans < 0 || clusters.empty())cout << "IMPOSSIBLE";
    else cout << "POSSIBLE\n" << ans;
}
int main()
{
    FastIO();
    Solve();
}