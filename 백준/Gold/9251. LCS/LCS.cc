#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
#include <cmath>
#include <string>
using namespace std;
char c1[1001];
char c2[1001];
int dp[1001][1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    scanf("%s", c1 + 1);
    scanf("%s", c2 + 1);
    int res = 0;
    for (int i = 1; c1[i]; ++i) {
        for (int j = 1; c2[j]; ++j) {
            if (c1[i] == c2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            res = max(res, dp[i][j]);
        }
    }
    cout << res;
}