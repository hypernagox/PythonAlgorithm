#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
int dp[301][301][10];
int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, q; cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int k = 0; k < 10; ++k)
            {
                dp[i][j][k] = dp[i - 1][j][k] + dp[i][j - 1][k] - dp[i - 1][j - 1][k];
            }
            int x; cin >> x;
            ++dp[i][j][x - 1];
        }
    }
    cin >> q;
    while (q--)
    {
        int a, b, c, d; cin >> a >> b >> c >> d;
        int cnt = 0;
        for (int i = 0; i < 10; ++i)
        {
            cnt += ((dp[c][d][i] - dp[a - 1][d][i] - dp[c][b - 1][i] + dp[a - 1][b - 1][i]) > 0);
        }
        cout << cnt << '\n';
    }
}