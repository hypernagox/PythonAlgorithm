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
int n, m, k;
char board[101][101];
bool visited[101][101];
constexpr const int dy[]{ -1,0,1,0 };
constexpr const int dx[]{ 0,1,0,-1 };
int GO(const int y, const int x)
{
    visited[y][x] = 1;
    int res = 1;
    for (int i = 0; i < 4; ++i)
    {
        const auto ny = y + dy[i];
        const auto nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
        if (board[ny][nx] == 0)continue;
        if (visited[ny][nx])continue;
        res += GO(ny, nx);
    }
    return res;
}
void Solve() noexcept
{
    cin >> n >> m >> k;
    while (k--)
    {
        int a, b; cin >> a >> b;
        board[a - 1][b - 1] = 1;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (visited[i][j])continue;
            if (board[i][j] == 0)continue;
            ans = max(ans, GO(i, j));
        }
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}