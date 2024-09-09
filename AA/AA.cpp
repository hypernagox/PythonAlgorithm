#include <iostream>
using namespace std;
uint64_t dp[101][10][1 << 10];
int n;
constexpr const int MOD = 1000000000;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (uint64_t i = 1; i <= 9; ++i) {
        dp[1][i][1 << i] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k < (1 << 10); ++k) {
               if (j == 0) {
                   dp[i][j][k | (1 << 0)] = ((dp[i][j][k | (1 << 0)] ) + (dp[i - 1][1][k] )) % MOD;
               }
               else if (j == 9) {
                   dp[i][j][k | (1 << 9)] = ((dp[i][j][k | (1 << 9)] ) + (dp[i - 1][8][k] )) % MOD;
               }
               else {
                   dp[i][j][k | (1 << j)] = ((dp[i][j][k | (1 << j)]) + (dp[i - 1][j - 1][k]) + (dp[i - 1][j + 1][k])) % MOD;
               }
            }
        }
    }
    uint64_t res = 0;
    for (int i = 0; i <= 9; ++i)
        res = (res % MOD + dp[n][i][(1 << 10) - 1] % MOD) % MOD;
    cout << res;
}