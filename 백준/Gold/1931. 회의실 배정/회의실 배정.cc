#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	vector<pair<int, int>> v;
	v.reserve(n);
	for (int i = 0; i < n; ++i) {
		int a, b; cin >> a >> b;
		v.emplace_back(a, b);
	}
	ranges::sort(v, [](auto& a, auto& b) {
		if (a.second == b.second) return a.first < b.first;
		return a.second < b.second;
		});
	int end_time = v.front().second;
	int res = 1;
	for (int i = 1; i < n; ++i) {
		if (end_time <= v[i].first) {
			end_time = v[i].second;
			++res;
		}
	}
	cout << res;
}