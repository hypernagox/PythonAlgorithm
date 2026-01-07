#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
int board[1001][1001];
int n, m;
constexpr const int dy[]{ -1,-1,0,1,1,1,0,-1 };
constexpr const int dx[]{ 0,1,1,1,0,-1,-1 ,-1 };
bool CanGo(const int y, const int x)
{
    if (y < 1 || x < 1 || y >n || x >m)return false;
    return true;
}
void GO(const int y,const int x, const int k)
{
    const auto ny = y + dy[k];
    const auto nx = x + dx[k];
    if (!CanGo(ny, nx))return;
    if (board[ny][nx] != 0 && board[ny][nx] != 4)return;
    board[ny][nx] = 4;
    GO(ny, nx, k);
}
constexpr const pi s[]
{
    {1,1},
    {-1,-1},
    {1,-1},
    {-1,1}
};
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < 3; ++i)
    {
        int a; cin >> a;
        while (a--)
        {
            int y, x; cin >> y >> x;
            board[y][x] = i + 1;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (board[i][j] == 1)
            {
                for (int k = 0; k < 8; ++k)
                {
                    GO(i, j, k);
                }
            }
            else if (board[i][j] == 2)
            {
                for(const auto [yy,xx]:s)
                {
                    const auto ny = i + 1*yy;
                    const auto nx = j + 2*xx;
                    if (CanGo(ny, nx) && board[ny][nx] == 0)
                    {
                        board[ny][nx] = 4;
                    }
                }
                for (const auto [yy, xx] : s)
                {
                    const auto ny = i + 2*yy;
                    const auto nx = j + 1*xx;
                    if (CanGo(ny, nx) && board[ny][nx] == 0)
                    {
                        board[ny][nx] = 4;
                    }
                }
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            res += board[i][j] == 0;
        }
    }
    cout << res;
}