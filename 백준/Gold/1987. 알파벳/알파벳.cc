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
int r, c;
char board[21][21];
constexpr const int dy[]{ -1,0,1,0 };
constexpr const int dx[]{ 0,1,0,-1 };
bool visited[26];
int GO(const int y, const int x)
{
    const auto val = board[y][x] - 'A';
    visited[val] = 1;
    int res = 1;
    for (int i = 0; i < 4; ++i)
    {
        const auto ny = y + dy[i];
        const auto nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= r || nx >= c)continue;
        const auto v = board[ny][nx] - 'A';
        if (visited[v])continue;
        res = max(res, GO(ny, nx) + 1);
    }
    visited[val] = 0;
    return res;
}
void Solve() noexcept
{
    cin >> r >> c;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cin >> board[i][j];
        }
    }
    cout << GO(0, 0);
}
int main()
{
    FastIO();
    Solve();
}