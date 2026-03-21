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
int visited[5][5];
bool CanGo(const int y, const int x)
{
    if (y < 0 || x < 0 || y >= 5 || x >= 5)return false;
    if (visited[y][x])return false;
    return true;
}
int ans;
constexpr const int dy[]{ -1,0,1,0 };
constexpr const int dx[]{ 0,1,0,-1 };
void GO(int y1, int x1, int y2, int x2)
{
    if (y1 == y2 && x1 == x2)
    {
        int s = 0;
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                s += visited[i][j];
            }
        }
        if (25 == s)++ans;
        return;
    }
    for (int i = 0; i < 4; ++i)
    {
        const auto ny1 = y1 + dy[i];
        const auto nx1 = x1 + dx[i];
        if (!CanGo(ny1, nx1))continue;
        for (int j = 0; j < 4; ++j)
        {
            const auto ny2 = y2 + dy[j];
            const auto nx2 = x2 + dx[j];
            if (!CanGo(ny2, nx2))continue;
            visited[ny1][nx1] = 1;
            visited[ny2][nx2] = 1;
            GO(ny1, nx1, ny2, nx2);
            visited[ny1][nx1] = 0;
            visited[ny2][nx2] = 0;
        }
    }
}
void Solve() noexcept
{
    int n; cin >> n;
    while (n--)
    {
        int a, b; cin >> a >> b;
        visited[a - 1][b - 1] = 1;
    }
    visited[0][0] = 1;
    visited[4][4] = 1;
    GO(0, 0, 4, 4);
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}