#include <bits/stdc++.h>
using namespace std;
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
constexpr const int INF = static_cast<const int>(1e9);
constexpr const int MIN_INF = -INF;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
constexpr const int dy[]{ -1,0,1,0 ,-1000};
constexpr const int dx[]{ 0,1,0,-1 ,-1000};
vector<string> board;
int n, m;
int visited[51][51];
bool CanGo(const int y, const int x)
{
    if (y < 0 || x < 0 || y >= n || x >= m)return false;
    if (visited[y][x])return false;
    if (board[y][x] == '*')return false;
    return true;
}
int GetGoal()
{
    int cnt = 0;
    for (const auto& s : board)
    {
        for (const auto ch : s)
        {
            cnt += (ch == '.');
        }
    }
    return cnt;
}
int ans = INF;
int g;
void GO(const int y, const int x, const int dir, const int num, const int d)
{
    auto ny = y + dy[dir];
    auto nx = x + dx[dir];
    if(num >= ans)return;
    if (d == g)
    {
        ans = min(ans, num);
        return;
    }
    visited[y][x] = 1;
    if (CanGo(ny, nx))
    {
        GO(ny, nx, dir, num, d + 1);
    }
    else
    {
        for (int k = 0; k < 4; ++k)
        {
            ny = y + dy[k];
            nx = x + dx[k];
            if (!CanGo(ny, nx))continue;
            GO(ny, nx, k, num + 1, d + 1);
        }
    }
    visited[y][x] = 0;
}
void Solve() noexcept
{
    int cnt = 0;
    vector<string> anss;
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; ++i)
        {
            string temp; cin >> temp;
            board.emplace_back(move(temp));
        }
        ans = INF;
        g = GetGoal();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (board[i][j] == '*')continue;
               // for (int k = 0; k < 4; ++k)
                {
                    visited[i][j] = 1;
                    GO(i, j, 4, 0, 1);
                    visited[i][j] = 0;
                }
            }
        }
        if (ans >= INF)ans = -1;
       // if (g == 1)ans = 0;
        cout << "Case " << ++cnt << ": " << ans << '\n';
        board.clear();
    }
}
int main()
{
    FastIO();
    Solve();
}