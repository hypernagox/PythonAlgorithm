#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<int> v;
	v.reserve(n);
	int res = 0;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		if (x >= n) {
			res += (x / n);
			v.emplace_back(x % n);
		}
		else {
			v.emplace_back(x);
		}
	}
	int remains = (int)v.size();
	int mn = 1 << 30;
	const auto sentinel = ranges::sort(v);
	for (auto iter = v.begin(); remains && iter != sentinel;) {
		const auto val = *iter;
		const auto up = ranges::upper_bound(iter, sentinel, val);
		remains -= up - iter;
		mn = min(mn, val + remains);
		iter = up;
	}
	cout << res + mn;
}