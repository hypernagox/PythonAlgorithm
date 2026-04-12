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
int n, m, h;
bool edges[31][11];
int ans = INF;
bool Check(const int y, const int start, const int dest)
{
    if (y == h)return start == dest;
    bool flag = true;
    for (int i = y; i < h; ++i)
    {
        if (start == 0)
        {
            if (edges[i][start])
            {
                return flag &= Check(i + 1, start + 1, dest);
            }
        }
        else if (start == n - 1)
        {
            if (edges[i][start - 1])
            {
                return flag &= Check(i + 1,start - 1, dest);
            }
        }
        else
        {
            if (edges[i][start])
            {
                return flag &= Check(i + 1, start + 1, dest);
            }
            else if (edges[i][start - 1])
            {
                return flag &= Check(i + 1, start - 1, dest);
            }
        }
        if (i == h - 1 && start == dest)return true;
    }
    return false;
}
void GO(const int cnt, const int lim)
{
    if (cnt >= ans)return;
    if (cnt == lim)
    {
        bool flag = true;
        for (int i = 0; i < n; ++i)
        {
            flag &= Check(0, i, i);
            if (!flag)return;
        }
        if (flag)
        {
            ans = min(ans, cnt);
        }
        return;
    }
    for (int y = 0; y < h; ++y)
    {
        for (int i = 0; i < n - 1; ++i)
        {
            if (edges[y][i] || edges[y][i + 1])continue;
            edges[y][i] = 1;
            GO(cnt + 1, lim);
            edges[y][i] = 0;
        }
    }
}
void Solve() noexcept
{
    cin >> n >> m >> h;
    for (int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        edges[a - 1][b - 1] = 1;
    }
    for (int i = 0; i <= 3; ++i)
    {
        GO(0, i);
    }
    if (ans >= INF)cout << -1;
    else cout << ans;
}
int main()
{
    FastIO();
    Solve();
}