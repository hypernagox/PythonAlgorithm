#include <iostream>
using namespace std;
int dp[10001];
int coin[101];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> coin[i];
	for (int i = 1; i <= n; ++i) {
		if (coin[i] > k)continue;
		dp[coin[i]] += 1;
		for (int j = coin[i] + 1; j <= k; ++j)
			dp[j] += dp[j - coin[i]];
	}
	cout << dp[k];
}