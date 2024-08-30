#include <iostream>
#include <algorithm>
#include <ranges>
using namespace std;
int arr[3][1000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 0; i < n; ++i)cin >> arr[0][i] >> arr[1][i] >> arr[2][i];
    int ans = 1 << 30;
    for (int i = 0; i < 3; ++i) {
        int dp[3][1000]{};
        for (int j = 0; j < 3; ++j) {
            if (i == j)dp[j][0] = arr[i][0];
            else dp[j][0] = 1 << 30;
        }
        dp[i][n - 1] = 1000 * 1000 + 1;
        for (int k = 1; k < n; ++k) {
            dp[0][k] = min(dp[1][k - 1], dp[2][k - 1]) + arr[0][k];
            dp[1][k] = min(dp[0][k - 1], dp[2][k - 1]) + arr[1][k];
            dp[2][k] = min(dp[1][k - 1], dp[0][k - 1]) + arr[2][k];
        }
        for (int v = 0; v < 3; ++v) {
            if (i == v)continue;
            ans = min(ans, dp[v][n - 1]);
        }
    }
    cout << ans;
}