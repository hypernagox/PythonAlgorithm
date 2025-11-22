#include <iostream>
#include <algorithm>
#include <ranges>
using namespace std;
int arr[1000001];
int dp[1000001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i)cin >> arr[i];
    int len = 1;
    dp[1] = arr[1];
    for (int i = 2; i <= n; ++i) {
        if (dp[len] < arr[i]) {
            dp[++len] = arr[i];
        }
        else {
            *ranges::lower_bound(dp + 1, dp + len + 1, arr[i]) = arr[i];
        }
    }
    cout << len;
}