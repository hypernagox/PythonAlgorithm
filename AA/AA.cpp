#include <iostream>
#include <algorithm>
#include <vector>
#include <ranges>
using namespace std;
int arr[1000001];
int dp[1000001];
int idx[1000001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) { cin >> arr[i]; }
	int len = 0;
	dp[len] = -(1 << 30);
	for (int i = 1; i <= n; ++i) {
		if (dp[len] < arr[i]) {
			++len;
			dp[len] = arr[i];
			idx[i] = len;
		}
		else {
			const auto iter = ranges::lower_bound(dp, dp + len, arr[i]);
			*iter = arr[i];
			idx[i] = distance(dp, iter);
		}	
	}
	cout << len << '\n';
	vector<int> v;
	v.reserve(len);
	for (int i = n; i >= 1; --i) {
		if (idx[i] == len) {
			v.emplace_back(arr[i]);
			--len;
		}
	}
	for (const auto i : v | views::reverse)cout << i << ' ';
}