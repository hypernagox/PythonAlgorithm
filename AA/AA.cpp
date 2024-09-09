#include <iostream>
#include <algorithm>
#include <ranges>
#include <map>
#include <vector>
#include <queue>
using namespace std;
uint64_t dp[101][11];
int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    
    // i번째 , k로 끝나는 수
    // dp[i][k] = dp[i-1][k-1] + dp[i-1][k+1];
    for (int i = 0; i <= 9; ++i) {
        dp[1][i] = 1;
        //dp[0][i] = 1;
    }
    dp[1][0] = 0;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= 9; ++j) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][1] % 1000000000;
            }
            else if (j == 9) {
                dp[i][j] = dp[i - 1][8] % 1000000000;
            }
            else {
                dp[i][j] = ((dp[i - 1][j - 1] % 1000000000) + (dp[i - 1][j + 1] % 1000000000)) % 1000000000;
            }
        }
    }
    uint64_t res = 0;
    for (int i = 0; i <= 9; ++i)
        res += (dp[n][i] % 1000000000);
    cout << res % 1000000000;
}