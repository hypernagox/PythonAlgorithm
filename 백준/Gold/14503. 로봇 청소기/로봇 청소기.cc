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
int n, m;
int board[51][51];
constexpr const int dy[]{ -1,0,1,0 };
constexpr const int dx[]{ 0,1,0,-1 };
bool CanGo(const int ny, const int nx)
{
    if (ny < 0 || nx < 0 || ny >= n || nx >= m)return false;
    if (board[ny][nx] == 1)return false;
    return true;
}
int GO(const int y, const int x, const int dir)
{
    const auto v = board[y][x] == 0;
    board[y][x] = 2;
    for (int i = 1; i <= 4; ++i)
    {
        const auto n_dir = (dir - i + 4) % 4;
        const auto ny = y + dy[n_dir];
        const auto nx = x + dx[n_dir];
        if (!CanGo(ny,nx))continue;
        if (board[ny][nx] != 0)continue;
        return GO(ny, nx, n_dir) + v;
    }
    const auto ny = y + dy[(dir + 2) % 4];
    const auto nx = x + dx[(dir + 2) % 4];
    if (CanGo(ny, nx))return GO(ny, nx, dir) + v;
    return v;
}
void Solve() noexcept
{
    cin >> n >> m;
    int y, x, dir; cin >> y >> x >> dir;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }
    cout << GO(y, x, dir);
}
int main()
{
    FastIO();
    Solve();
}