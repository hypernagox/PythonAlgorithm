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
char board[11][11];
constexpr const int dy[]{ -1,0,1,0 };
constexpr const int dx[]{ 0,1,0,-1 };
int visited[11][11][11][11];
struct Data
{
    pi r_pos;
    pi b_pos;
};
pi holl;
bool CanGo(const int y, const int x)
{
    if (y < 0 || x < 0 || y >= n || x >= m)return false;
    if (board[y][x] == '#' || board[y][x]=='X')return false;
    return true;
}
void Move(pi& target, const pi o, const int dir)
{
    for (;;)
    {
        const int ny = target.first + dy[dir];
        const int nx = target.second + dx[dir];

        if (!CanGo(ny, nx))break;

        if (make_pair(ny, nx) == holl)
        {
            target = make_pair(ny, nx);
            break;
        }

        if (o != holl && make_pair(ny, nx) == o)break;

        target.first = ny;
        target.second = nx;
    }
}
void Solve() noexcept
{
    cin >> n >> m;
    pi r_pos;
    pi b_pos;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 'R')
            {
                board[i][j] = '.';
                r_pos = make_pair(i, j);
            }
            if (board[i][j] == 'B')
            {
                board[i][j] = '.';
                b_pos = make_pair(i, j);
            }
            if (board[i][j] == 'O')
            {
                holl = make_pair(i, j);
            }
        }
    }
    queue<Data> q;
    q.emplace(r_pos, b_pos);
    visited[r_pos.first][r_pos.second][b_pos.first][b_pos.second] = 1;
    int ans = INF;
    while (q.size())
    {
        const auto [r, b] = q.front();
        const auto [ry, rx] = r;
        const auto [by, bx] = b;
        if (r == holl && b != holl)
        {
            ans = min(ans,visited[ry][rx][by][bx] - 1);
        }
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            auto rr = r;
            auto bb = b;
            if (i == 0)
            {
                if (ry < by)
                {
                    Move(rr,bb, i);
                    Move(bb,rr, i);
                }
                else
                {
                    Move(bb,rr, i);
                    Move(rr,bb, i);
                }
            }
            if (i == 1)
            {
                if (rx > bx)
                {
                    Move(rr,bb, i);
                    Move(bb,rr, i);
                }
                else
                {
                    Move(bb,rr, i);
                    Move(rr,bb, i);
                }
            }
            if (i == 2)
            {
                if (ry > by)
                {
                    Move(rr,bb, i);
                    Move(bb,rr, i);
                }
                else
                {
                    Move(bb,rr, i);
                    Move(rr,bb, i);
                }
            }
            if (i == 3)
            {
                if (rx < bx)
                {
                    Move(rr,bb, i);
                    Move(bb,rr, i);
                }
                else
                {
                    Move(bb,rr, i);
                    Move(rr,bb, i);
                }
            }
            auto nry = rr.first;
            auto nrx = rr.second;
            auto nby = bb.first;
            auto nbx = bb.second;
            if (rr == r && bb == b)continue;
            if (bb == holl)continue;
            if (visited[nry][nrx][nby][nbx])continue;

            visited[nry][nrx][nby][nbx] = visited[ry][rx][by][bx] + 1;
            if (visited[nry][nrx][nby][nbx] >= 12)continue;

            if (rr == holl)
            {
                cout << visited[nry][nrx][nby][nbx] - 1;
                return;
            }
            q.emplace(make_pair(nry, nrx), make_pair(nby, nbx));
        }
    }
    if (ans >= INF)cout << -1;
    else cout << ans;
}
int main()
{
    FastIO();
    Solve();
}