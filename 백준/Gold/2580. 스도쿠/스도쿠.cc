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
string board[9];
vector<pi> nokori;
bool Check(const int y, const int x)
{
    for (int i = 0; i < 9; ++i)
    {
        if (board[y][x] == board[i][x] && i != y)return false;
        if (board[y][x] == board[y][i] && i != x)return false;
    }
    const auto yy = (y / 3) * 3;
    const auto xx = (x / 3) * 3;
    for (int i = yy; i < yy + 3; ++i)
    {
        for (int j = xx; j < xx + 3; ++j)
        {
            if (y == i && x == j)continue;
            if (board[i][j] == board[y][x])return false;
        }
    }
    return true;
}
int n;
void GO(const int cnt = 0)
{
    if (cnt == n)
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        exit(0);
        return;
    }
    const auto [i, j] = nokori[cnt];
    for (int k = 1; k <= 9; ++k)
    {
        const char target = k + '0';
        board[i][j] = target;
        if (Check(i, j))
        {
            GO(cnt + 1);
        }
        board[i][j] = 0 + '0';
    }
}
void Solve() noexcept
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            char c; cin >> c;
            if (c == '0')
            {
                ++n;
                nokori.emplace_back(i, j);
            }
            board[i] += c;
        }
    }
    GO();
}
int main()
{
    FastIO();
    Solve();
}