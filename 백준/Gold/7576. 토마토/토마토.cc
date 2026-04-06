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
bool IsFinish()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (board[i][j] == 0)return false;
        }
    }
    return true;
}
vector<pi> targets;
bool visited[1001][1001];
bool GO()
{
    vector<pi> v;
    for (const auto [i, j] : targets)
    {
        for (int k = 0; k < 4; ++k)
        {
            const auto ny = i + dy[k];
            const auto nx = j + dx[k];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
            if (board[ny][nx] != 0)continue;
            if (visited[ny][nx])continue;
            visited[ny][nx] = 1;
            v.emplace_back(ny, nx);
        }
    }
    for (const auto [y, x] : v)
    {
        board[y][x] = 1;
    }
    targets.swap(v);
    return targets.empty();
}
void Solve() noexcept
{
    cin >> m >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
            {
                targets.emplace_back(i, j);
            }
        }
    }
    int cnt = 0;
    while (!IsFinish())
    {
        if (GO())
        {
            cnt = -1;
            break;
        }
        ++cnt;
    }
    cout << cnt;
}
int main()
{
    FastIO();
    Solve();
}