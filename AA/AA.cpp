#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int dp[501];
	int arr[13];
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> arr[i];
	cin >> m;
	for (auto& i : dp)i = 54321;
	dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = arr[i]; j <= m; ++j) {
			dp[j] = min(dp[j], dp[j - arr[i]] + 1);
		}
	}
	cout << dp[m];
}
