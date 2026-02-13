#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
char coins[101][101];
int n, m;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            char c; cin >> c;
            coins[i][j] = c - '0';
        }
    }
    int ans = 0;
    for (int i = n - 1; i  >= 0; --i)
    {
        for (int j = m - 1; j >= 0; --j)
        {
            if (coins[i][j])
            {
                ++ans;
                for (int a = 0; a <= i; ++a)
                {
                    for (int b = 0; b <= j; ++b)
                    {
                        coins[a][b] = !coins[a][b];
                    }
                }
            }
        }
    }
    cout << ans;
}