#include <bits/stdc++.h>
using namespace std;
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
constexpr const int INF = 987654321;
constexpr const int MIN_INF = INF * -1;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
constexpr const int dy[]{ -1,0,1,0 };
constexpr const int dx[]{ 0,1,0,-1 };
int n, m;
char board[501][501];
int state[501][501]; // 0 미방문, 1 방문중, 2 방문 끝
int memo[501][501];
map<char, int> dirs
{
    {'U',0},
    {'R',1},
    {'D',2},
    {'L',3},
};
bool CanGo(const int y, const int x)
{
    if (y < 0 || x < 0 || y >= n || x >= m)return false;
    return true;
}
int GO(const int y, const int x)
{
    if (!CanGo(y, x))
    {
        return 1;
    }
    if (1 == state[y][x])
    {
        return 0;
    }
    auto& ref = memo[y][x];
    if (~ref)return ref;
    state[y][x] = 1;
    const auto val = board[y][x];
    const auto dir = dirs[val];
    const auto ny = y + dy[dir];
    const auto nx = x + dx[dir];
    const auto res = GO(ny, nx);
    state[y][x] = 2;
    return ref = res;
}
void Solve()noexcept
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }
    memset(memo, -1, sizeof(memo));
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            ans += GO(i, j);
        }
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}