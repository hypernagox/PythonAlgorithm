#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
int house[33][33];
int n;
ull memo[3][33][33];
bool CanGO(const int y, const int x)noexcept
{
    if (y < 0 || x < 0 || y >= n || x >= n)return false;
    if (house[y][x])return false;
    return true;
}
ull GO(const int cur_shape,const int y,const int x)noexcept
{
    if (y == n - 1 && x == n - 1)
    {
        return 1;
    }
    auto& ref = memo[cur_shape][y][x];
    if (-1 != ref)return ref;
    ref = 0;
    ull s = 0;
    if (cur_shape == 0)
    {
        if (CanGO(y, x + 1))
        {
            s += GO(cur_shape, y, x + 1);
        }
        if (CanGO(y + 1, x) && CanGO(y + 1, x + 1) && CanGO(y, x + 1))
        {
            s += GO(2, y + 1, x + 1);
        }
    }
    else if (cur_shape == 1)
    {
        if (CanGO(y + 1, x))
        {
            s += GO(cur_shape, y + 1, x);
        }
        if (CanGO(y + 1, x) && CanGO(y + 1, x + 1) && CanGO(y, x + 1))
        {
            s += GO(2, y + 1, x + 1);
        }
    }
    else if (cur_shape == 2)
    {
        if (CanGO(y, x + 1))
        {
            s += GO(0, y, x + 1);
        }
        if (CanGO(y + 1, x))
        {
            s += GO(1, y + 1, x);
        }
        if (CanGO(y + 1, x) && CanGO(y + 1, x + 1) && CanGO(y, x + 1))
        {
            s += GO(2, y + 1, x + 1);
        }
    }
    return ref = s;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    memset(memo, -1, sizeof(memo));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> house[i][j];
        }
    }
    cout << GO(0, 0, 1);
}