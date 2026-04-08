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
int board[1001][1001];
constexpr const int dy[]{ -1,0,1,0 };
constexpr const int dx[]{ 0,1,0,-1 };
void Solve() noexcept
{
    cin >> m >> n;
    queue<pi> q;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
            {
                q.emplace(i, j);
            }
        }
    }
    int ans = 0;
    while (q.size())
    {
        const auto [y, x] = q.front();
        q.pop();
        ans = max(ans, board[y][x]);
        for (int i = 0; i < 4; ++i)
        {
            const auto ny = y + dy[i];
            const auto nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
            if (board[ny][nx] != 0)continue;
            board[ny][nx] = board[y][x] + 1;
            q.emplace(ny, nx);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (board[i][j] == 0)
            {
                cout << -1;
                return;
            }
        }
    }
    cout << ans - 1;
}
int main()
{
    FastIO();
    Solve();
}