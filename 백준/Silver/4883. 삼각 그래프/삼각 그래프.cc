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
int board[100001][4];
ll memo[100001][4];
int n;
ll GO(const int y, const int x)
{
    if (y < 0 || x < 0 || y >= n || x >= 3)return INF;
    if (y == n - 1 && x == 1)
    {
        return board[y][x];
    }
    auto& ref = memo[y][x];
    if (~ref)return ref;
    ll a = INF;
    ll b = INF;
    ll c = INF;
    ll d = INF;
    if (x == 0)
    {
        a = GO(y + 1, x);
        b = GO(y + 1, x + 1);
        c = GO(y, x + 1);
    }
    else if (x == 1)
    {
        a = GO(y, x + 1);
        b = GO(y + 1, x);
        c = GO(y + 1, x - 1);
        d = GO(y + 1, x + 1);
    }
    else
    {
        a = GO(y + 1, x);
        b = GO(y + 1, x - 1);
    }
    return ref = min({ a,b,c,d }) + board[y][x];
}
void Solve() noexcept
{
    int cnt = 0;
    for (;;)
    {
        cin >> n;
        if (0 == n)return;
        memset(memo, -1, sizeof(memo));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                cin >> board[i][j];
            }
        }
        cout << ++cnt << ". " << GO(0, 1) << '\n';
    }
}
int main()
{
    FastIO();
    Solve();
}