#include <bits/stdc++.h>
using namespace std;
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
constexpr const int INF = static_cast<const int>(1e9);
constexpr const int MIN_INF = -INF;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
char board[65][65];
int Check(const int sy, const int sx, const int ey, const int ex)
{
    bool one_flag = true;
    bool zero_flag = true;
    for (int i = sy; i < ey; ++i)
    {
        for (int j = sx; j < ex; ++j)
        {
            one_flag &= board[i][j] == '1';
            zero_flag &= board[i][j] == '0';
        }
    }
    if (one_flag)return 1;
    if (zero_flag)return 0;
    return -1;
}
void GO(const int sy, const int sx, const int h, const int w)noexcept
{
    const auto val = Check(sy, sx, sy + h, sx + w);
    if (-1 == val)
    {
        cout << '(';
        GO(sy, sx, h / 2, w / 2); // 왼쪽위
        GO(sy, sx + w / 2, h / 2, w / 2); // 오른쪽위
        GO(sy + h / 2, sx, h / 2, w / 2); // 왼쪽아래
        GO(sy + h / 2, sx + w / 2, h / 2, w / 2); // 오른쪽아래
        cout << ')';
    }
    else
    {
        cout << val;
    }
}
void Solve()noexcept
{
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }
    GO(0, 0, n, n);
}
int main()
{
    FastIO();
    Solve();
}
