#include <iostream>
#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;
pair<int, int> dp[1000];
int dp2[1000]{};

void go(int n)
{
	if (dp2[n] != n)
		go(dp2[n]);
	cout << dp[n].first << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) { cin >> dp[i].first; dp2[i] = i; }
	dp[0].second = 1;
	int res = 1;
	int max_idx = 0;
	for (int i = 0; i < n; ++i) {
		int max_v = 1;
		for (int j = i ; j >= 0; --j) {
			if (dp[j].first < dp[i].first && dp[j].second + 1 > max_v) {
				dp2[i] = j;
				max_v = dp[j].second + 1;
			}
		}
		dp[i].second = max_v;
		if (res < max_v)
		{
			max_idx = i;
			res = max_v;
		}
	}
	cout << res << '\n';
	go(max_idx);
}