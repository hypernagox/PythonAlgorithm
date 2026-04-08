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
char b1[51][51];
char b2[51][51];
int n, m;
void Change(const int y, const int x)
{
    const auto yy = y + 3;
    const auto xx = x + 3;
    if (yy > n || xx > m)return;
    for (int i = y; i < yy; ++i)
    {
        for (int j = x; j < xx; ++j)
        {
            if (b1[i][j] == '0')b1[i][j] = '1';
            else b1[i][j] = '0';
        }
    }
}
void Solve() noexcept
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> b1[i][j];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> b2[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (b1[i][j] != b2[i][j])
            {
                ++ans;
                Change(i, j);
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (b1[i][j] != b2[i][j])
            {
                cout << -1;
                return;
            }
        }
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}