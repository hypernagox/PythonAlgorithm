#include <iostream>
#include <algorithm>
#include <ranges>
using namespace std;
int t[501];
int dp[501];
int n;
int go(int idx,int d)
{
	if (d >= n)return 0;
	if (dp[idx])return dp[idx];
	return dp[idx] = max(go(d + idx, d + 1), go(d + 1 + idx, d + 1)) + t[idx];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= (n * (n + 1)) / 2; ++i)cin >> t[i];
	go(1, 1);
	cout << dp[1];
}