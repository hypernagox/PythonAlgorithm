#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
char board[101][101];
int n;
constexpr const int dy[]{ 0,1 };
constexpr const int dx[]{ 1,0 };
bool CanGo(const int y, const int x)
{
    if (y < 0 || x < 0 || y >= n || x >= n)return false;
    return true;
}
int GO(const int y,const int x, const int dir, const int cnt)
{
    if (!CanGo(y, x))
    {
        if (cnt >= 2) return 1;
        else return 0;
    }
    int res = 0;
    if ('.' == board[y][x])
    {
        res += GO(y + dy[dir], x + dx[dir], dir, cnt + 1);
    }
    else
    {
        if (cnt >= 2)++res;
        res += GO(y + dy[dir], x + dx[dir], dir, 0);
    }
    return res;
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
    int res_a = 0;
    int res_b = 0;
    for (int i = 0; i < n; ++i)
    {
        res_a += GO(i, 0, 0, 0);
        res_b += GO(0, i, 1, 0);
    }
    cout << res_a << ' ' << res_b;
}