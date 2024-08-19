#include <iostream>
#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

int dp[20][20];
int arr[20][20];

int go(int i,int j)
{
	if (0 > i || 0 > j)return 54321;
	if (dp[i][j])return dp[i][j];
	return dp[i][j] = min(go(i - 1, j), go(i, j - 1)) + arr[i][j];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
		}
	}
	dp[0][0] = arr[0][0];
	//for (int i = 1; i < n; ++i) {
	//	dp[0][i] = dp[0][i - 1] + arr[0][i];
	//	dp[i][0] = dp[i - 1][0] + arr[i][0];
	//}
	go(n - 1, n - 1);
	cout << dp[n - 1][n - 1];
}