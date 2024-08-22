#include <iostream>
#include <algorithm>
#include <ranges>
using namespace std;
int arr[2][100002];
int dp[2][100002];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < 2; ++i) {
			int m = n;
			while (m--) {
				cin >> arr[i][n - m];
			}
		}
		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];
		
		for (int i = 2; i <= n; ++i) {
			dp[0][i] = max(dp[1][i - 1] + arr[0][i], max(dp[1][i - 2], dp[0][i - 2]) + arr[0][i]);
			dp[1][i] = max(dp[0][i - 1] + arr[1][i], max(dp[0][i - 2], dp[1][i - 2]) + arr[1][i]);
		}
		cout << max(dp[0][n], dp[1][n]) << '\n';
	}
}