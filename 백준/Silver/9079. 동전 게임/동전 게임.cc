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
char board[3][3];
vector<char*> v[8];
bool visited[8];
void Change(char& c)
{
    if ('H' == c)c = 'T';
    else c = 'H';
}
void Flip(const int num)
{
    for (const auto i : v[num])
    {
        Change(*i);
    }
}
void Init()
{
    int cnt = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            v[cnt].emplace_back(&board[i][j]);
        }
        ++cnt;
    }
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            v[cnt].emplace_back(&board[j][i]);
        }
        ++cnt;
    }
    v[cnt].emplace_back(&board[0][0]);
    v[cnt].emplace_back(&board[1][1]);
    v[cnt].emplace_back(&board[2][2]);
    ++cnt;
    v[cnt].emplace_back(&board[0][2]);
    v[cnt].emplace_back(&board[1][1]);
    v[cnt].emplace_back(&board[2][0]);
    ++cnt;
}
bool Check()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] != board[0][0])return false;
        }
    }
    return true;
}
int ans = INF;
void GO(const int cnt)
{
    if (cnt >= ans)return;
    if (Check())
    {
        ans = min(ans, cnt);
        return;
    }
    for (int i = 0; i < 8; ++i)
    {
        if (visited[i])continue;
        visited[i] = 1;
        Flip(i);
        GO(cnt + 1);
        Flip(i);
        visited[i] = 0;
    }
}
void Solve() noexcept
{   
    int t; cin >> t;
    Init();
    while (t--)
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                cin >> board[i][j];
            }
        }
        GO(0);
        if (ans >= INF)cout << -1 << '\n';
        else cout << ans << '\n';
        ans = INF;
    }
}
int main()
{
    FastIO();
    Solve();
}