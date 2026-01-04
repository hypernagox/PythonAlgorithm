#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
short D[20][20];
int n;
int memo[1 << 20];
int GO(const int mask)noexcept
{
    if (mask == (1 << n) - 1) return 0;
    int& ref = memo[mask];
    if (ref != -1) return ref;
    const int human = __builtin_popcount((unsigned)mask);
    int res = INF;
    for (int j = 0; j < n; ++j)
    {
        if (mask & (1 << j)) continue;
        res = min(res, GO(mask | (1 << j)) + D[human][j]);
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
            cin >> D[i][j];
        }
    }
    memset(memo, -1, sizeof(memo));
    cout << GO(0);
}