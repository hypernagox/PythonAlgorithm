#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ranges>
#include <numeric>
#include <queue>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	int res = 0;
	vector<pair<int, int>> v;
	priority_queue<pair<int, int>> pq;
	for (int i = 0; i < n; ++i) {
		int p, d; cin >> p >> d;
		v.emplace_back(d, -p);
	}
	sort(v.begin(), v.end());
	for (const auto [d, p] : v) {
		const auto pp = -p;
		const auto dd = d;
		res += pp;
		pq.emplace(p, dd);
		while (pq.size() > dd) {
			res += pq.top().first; pq.pop();
		}
	}
	cout << res;
}