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
constexpr const int dy[]{ -1,-1,0,1,1,1,0,-1 };
constexpr const int dx[]{ 0,1,1,1,0,-1,-1,-1 };
int board[16][16];
int n;
bool CanGo(const int ny, const int nx)
{
    if (ny < 0 || nx < 0 || ny >= n || nx >= n)return false;
    return true;
}
void Fill(const int y, const int x, const int flag)
{
    for (int i = 0; i < 8; ++i)
    {
        auto ny = y + dy[i];
        auto nx = x + dx[i];
        while (CanGo(ny, nx))
        {
            board[ny][nx] += flag;
            ny += dy[i];
            nx += dx[i];
        }
    }
}
int GO(const int d)
{
    if (d == n)
    {
        return 1;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (0 != board[d][i])continue;
        board[d][i]++;
        Fill(d, i, 1);
        ans += GO(d + 1);
        board[d][i]--;
        Fill(d, i, -1);
    }
    return ans;
}
void Solve() noexcept
{
    cin >> n;
    cout << GO(0);
}
int main()
{
    FastIO();
    Solve();
}