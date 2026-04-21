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
int r, c, k;
char board[51][51];
constexpr const int dy[]{ -1,0,1,0 };
constexpr const int dx[]{ 0,1,0,-1 };
map<char, int> dir
{
    {'U',0},
    {'R',1},
    {'D',2},
    {'L',3},
};
bool visited[51][51][2][2];
int GO(const int y, const int x, const int a, const int b)
{
    if (y < 0 || x < 0 || y >= r || x >= c)return 0;
    if (y == r - 1 && x == c - 1)return 1;
    if (visited[y][x][a][b])return 0;
    visited[y][x][a][b] = 1;
    const auto d = dir[board[y][x]];
    const auto ny = y + dy[d];
    const auto nx = x + dx[d];
    bool res = false;
    if (a)
    {
        // r 주문서
        const auto d2 = (d + 1) % 4;
        res |= GO(y + dy[d2], x + dx[d2], a - 1, b);
    }
    if (b)
    {
        // l 주문서
        const auto d2 = (d - 1 + 4) % 4;
        res |= GO(y + dy[d2], x + dx[d2], a, b - 1);
    }
    res |= GO(ny, nx, a, b);
    return res;   
}
void Solve() noexcept
{
    cin >> r >> c >> k;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cin >> board[i][j];
        }
    }
    if (GO(0, 0, k, k))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}
int main()
{
    FastIO();
    Solve();
}