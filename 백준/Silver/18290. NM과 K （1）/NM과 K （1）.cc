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
int board[11][11];
bool visited[11][11];
int n, m, k;
int ans = -INF;
vector<pi> v;
bool Check(const int y, const int x)
{
    for (const auto [yy, xx] : v)
    {
        for (int i = 0; i < 4; ++i)
        {
            const auto ny = y + dy[i];
            const auto nx = x + dx[i];
            if (yy == ny && xx == nx)return false;
        }
    }
    return true;
}
void GO(const int y,const int x, const int depth)
{
    if (depth == k)
    {
        int s = 0;
        for (const auto [yy, xx] : v)
        {
            s += board[yy][xx];
        }
        ans = max(ans, s);
        return;
    }
    for (int i = y; i < n; ++i)
    {
        for (int j = x; j < m; ++j)
        {
            if (visited[i][j] || !Check(i, j))continue;
            visited[i][j] = 1;
            v.emplace_back(i, j);
            GO(y, x, depth + 1);
            v.pop_back();
            visited[i][j] = 0;
        }
    }
    
}
void Solve()noexcept
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }
    GO(0, 0, 0);
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}