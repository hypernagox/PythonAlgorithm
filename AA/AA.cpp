#include <iostream>
#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	pair<int, int> dp[1000];
	cin >> n;
	for (int i = 0; i < n; ++i)cin >> dp[i].first;
	dp[0].second = 1;
	int res = 1;
	for (int i = 1; i < n; ++i) {
		int max_v = 1;
		for (int j = i - 1; j >= 0; --j) {
			if (dp[j].first < dp[i].first && dp[j].second + 1 > max_v) {
				max_v = dp[j].second + 1;
			}
		}
		dp[i].second = max_v;
		res = max(res, max_v);
	}
	cout << res << '\n';
	vector<int> v;
	for (int i = n - 1; i >= 0; --i) {
		if (dp[i].second == res) {
			v.emplace_back(dp[i].first);
			--res;
		}
	}
	ranges::sort(v);
	for (auto i : v)cout << i << ' ';
}