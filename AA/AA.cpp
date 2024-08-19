#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int dp[100001]{};
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m;
	int res = 0;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int w, v;
		cin >> w >> v;
		for (int j = m; j >= w; --j) {
			dp[j] = max(dp[j], dp[j - w] + v);
			res = max(dp[j], res);
		}
	}
	cout << res;
}
