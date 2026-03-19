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
int board[65][65];
int n, q;
int N;
int temp[65][65];
bool visited[65][65];
constexpr const int dy[]{ -1,0,1,0 };
constexpr const int dx[]{ 0,1,0,-1 };
pi Rotate(const int y, const int x, const int w)
{
    return { x, w - 1 - y };
}
void Storm(const int y, const int x, const int w)
{
    for (int i = y; i < y + w; ++i)
    {
        for (int j = x; j < x + w; ++j)
        {
            temp[i][j] = board[i][j];
        }
    }
    for (int i = y; i < y + w; ++i)
    {
        for (int j = x; j < x + w; ++j)
        {
            const int localY = i - y;
            const int localX = j - x;
            const auto [rotY, rotX] = Rotate(localY, localX, w);
            const int yy = y + rotY;
            const int xx = x + rotX;
            board[yy][xx] = temp[i][j];
        }
    }
}
void GO(const int y,const int x,const int w, const int dest)
{
    if (dest == w)
    {
        Storm(y, x, w);
        return;
    }
    GO(y, x, w / 2, dest);
    GO(y, x + w / 2, w / 2, dest);
    GO(y + w / 2, x, w / 2, dest);
    GO(y + w / 2, x + w / 2, w / 2, dest);
}
int dfs(const int y, const int x)
{
    visited[y][x] = 1;
    int res = 1;
    for (int k = 0; k < 4; ++k)
    {
        const auto ny = y + dy[k];
        const auto nx = x + dx[k];
        if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
        if (board[ny][nx] == 0)continue;
        if (visited[ny][nx])continue;
        res += dfs(ny, nx);
    }
    return res;
}
void Solve() noexcept
{
    cin >> n >> q;
    N = (int)pow(2, n);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
        }
    }
    while (q--)
    {
        int d; cin >> d;
        GO(0, 0, N, (int)pow(2, d));
        vector<pi> p;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                int cnt = 0;
                if (board[i][j] == 0)continue;
                for (int k = 0; k < 4; ++k)
                {
                    const auto ny = i + dy[k];
                    const auto nx = j + dx[k];
                    if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
                    if (board[ny][nx] == 0)continue;
                    ++cnt;
                }
                if (cnt < 3)
                {
                    p.emplace_back(i, j);
                }
            }
        }
        for (const auto [y, x] : p)--board[y][x];
    }
    int s = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            s += board[i][j];
        }
    }
    int s2 = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (visited[i][j])continue;
            if (board[i][j] == 0)continue;
            s2 = max(s2, dfs(i, j));
        }
    }
    cout << s << '\n' << s2;
}
int main()
{
    FastIO();
    Solve();
}