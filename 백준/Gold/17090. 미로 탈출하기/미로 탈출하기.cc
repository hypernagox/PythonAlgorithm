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
int dirs[26];
bool CanGo(const int y, const int x)
{
    if (y < 0 || x < 0 || y >= n || x >= m)return false;
    return true;
}
int GO(const int y, const int x)
{
    if (!CanGo(y, x))
    {
        return 2; // 2는 가능
    }
    if (1 == state[y][x])
    {
        return 1; // 1은 불가
    }
    auto& ref = state[y][x];
    if (ref)return ref; // 0은 아직모르지만 1이나 2 값이 들어있으면 아는것임
    ref = 1;
    const auto val = board[y][x];
    const auto dir = dirs[val];
    const auto ny = y + dy[dir];
    const auto nx = x + dx[dir];
    const auto res = GO(ny, nx);
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
            board[i][j] -= 'A';
        }
    }
    dirs['U' - 'A'] = 0;
    dirs['R' - 'A'] = 1;
    dirs['D' - 'A'] = 2;
    dirs['L' - 'A'] = 3;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            ans += GO(i, j) - 1;
        }
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}