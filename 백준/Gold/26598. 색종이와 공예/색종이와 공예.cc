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
char board[1001][1001];
bool visited[1001][1001];
constexpr const int dy[]{ -1,0,1,0 };
constexpr const int dx[]{ 0,1,0,-1 };
set<pi> s1,s2;
void GO(const int y,const int x, const char target)
{
    visited[y][x] = 1;
    s1.emplace(y, x);
    s2.emplace(x, y);
    for (int i = 0; i < 4; ++i)
    {
        const auto ny = y + dy[i];
        const auto nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
        if (visited[ny][nx])continue;
        if (target != board[ny][nx])continue;
        GO(ny, nx, target);
    }
}
void Solve() noexcept
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            char c; cin >> c;
            board[i][j] = c;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (visited[i][j])continue;
            GO(i, j, board[i][j]);
            const auto y1 = s1.begin()->first;
            const auto x1 = s2.begin()->first;
            const auto y2 = s1.rbegin()->first;
            const auto x2 = s2.rbegin()->first;
            const auto w = (y2 - y1 + 1) * (x2 - x1 + 1);
            if (w != s1.size())
            {
                cout << "BaboBabo";
                return;
            }
            s1.clear();
            s2.clear();
        }
    }
    cout << "dd";
}
int main()
{
    FastIO();
    Solve();
}