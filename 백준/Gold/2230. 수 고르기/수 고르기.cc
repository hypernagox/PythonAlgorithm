#include <iostream>
#include <ranges>
#include <algorithm>
using namespace std;
long long arr[100001];
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; ++i)cin >> arr[i];
	ranges::sort(arr, arr + n);
	arr[n] = INT64_MAX / 2;
	long long res = INT64_MAX;
	for (int i = 0; i < n - 1; ++i) {
		res = min(res, *ranges::lower_bound(arr + i, arr + n, arr[i] + m) - arr[i]);
	}
	cout << res;
}