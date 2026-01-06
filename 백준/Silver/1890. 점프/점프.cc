#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
int n;
int board[101][101];
constexpr const int dy[]{ 1,0 };
constexpr const int dx[]{ 0,1 };
ull memo[101][101];
ull GO(const int y, const int x)
{
    if (y == n - 1 && x == n - 1)return 1;
    auto& ref = memo[y][x];
    if (~ref)return ref;
    const auto delta = board[y][x];
    ull res = 0;
    if (delta)
    {
        for (int i = 0; i < 2; ++i)
        {
            const auto ny = y + dy[i] * delta;
            const auto nx = x + dx[i] * delta;
            if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
            res += GO(ny, nx);
        }
    }
    return ref = res;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }
    memset(memo, -1, sizeof(memo));
    cout << GO(0, 0);
}