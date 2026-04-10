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
constexpr const int dy[]{ -1,0,1,0 };
constexpr const int dx[]{ 0,1,0,-1 };
int visited[1001][1001];
bool fire[1001][1001];
char board[1001][1001];
int c, r;
vector<pi> fire_place;
bool CanGo(const int y, const int x)
{
    if (y < 0 || x < 0 || y >= r || x >= c)return false;
    return true;
}
vector<pi> s;
void Fire()
{
    for (const auto [i, j] : fire_place)
    {
        for (int k = 0; k < 4; ++k)
        {
            const auto ny = i + dy[k];
            const auto nx = j + dx[k];
            if (CanGo(ny, nx) == false)continue;
            if (board[ny][nx] != '.')continue;
            if (fire[ny][nx])continue;
            fire[ny][nx] = 1;
            s.emplace_back(ny, nx);
        }
    }
    fire_place.clear();
    for (const auto [i, j] : s)
    {
        board[i][j] = '*';
        fire_place.emplace_back(i, j);
    }
    s.clear();
}
struct Data
{
    int y;
    int x;
    int level;
};
void Solve() noexcept
{
    int t; cin >> t;
    pi start{};
    queue<Data> q;
    fire_place.reserve(1024);
    s.reserve(1024);
    while (t--)
    {
        cin >> c >> r;
        while (q.size())q.pop();
        fire_place.clear();
        memset(visited, 0, sizeof(visited));
        memset(fire, 0, sizeof(fire));
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                cin >> board[i][j];
                if (board[i][j] == '@')
                {
                    board[i][j] = '.';
                    start = make_pair(i, j);
                }
                else if (board[i][j] == '*')
                {
                    fire_place.emplace_back(i, j);
                    fire[i][j] = 1;
                }
            }
        }
        q.emplace(start.first, start.second, 0);
        visited[start.first][start.second] = 1;
        int ans = 0;
        int cur_level = -1;
        while (q.size())
        {
            const auto [y, x, level] = q.front();
            if (cur_level != level)
            {
                cur_level = level;
                Fire();
            }
            q.pop();
            for (int k = 0; k < 4; ++k)
            {
                const auto ny = y + dy[k];
                const auto nx = x + dx[k];
                if (CanGo(ny, nx) == false)
                {
                    ans = visited[y][x];
                    break;
                }
                if (board[ny][nx] != '.')continue;
                if (visited[ny][nx])continue;
                visited[ny][nx] = visited[y][x] + 1;
                q.emplace(ny, nx, level + 1);
            }
            if (ans)break;
        }
        if (ans)cout << ans << '\n';
        else cout << "IMPOSSIBLE\n";
    }
}
int main()
{
    FastIO();
    Solve();
}