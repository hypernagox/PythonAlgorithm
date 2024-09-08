#include <iostream>
#include <algorithm>
using namespace std;
int dp[16][1 << 16];
int g[16][16];
uint16_t n;
uint16_t DONE;
int go(uint16_t cur, uint16_t visited)
{
    if (visited == DONE) return g[cur][0];
    if (dp[cur][visited])return dp[cur][visited];
    dp[cur][visited] = 987654321;
    for (int i = 0; i < n; ++i) {
        if (g[cur][i] == 987654321)continue;
        if ((visited & (1 << i)) == (1 << i))continue;
        dp[cur][visited] = min(dp[cur][visited], g[cur][i] + go(i, visited | (1 << i)));
    }
    return dp[cur][visited];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    DONE = (1 << n) - 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x; cin >> x;
            if (x)
                g[i][j] = x;
            else
                g[i][j] = 987654321;
        }
    }
    cout << go(0, 1);
}