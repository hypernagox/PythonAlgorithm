#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	vector<int> v1, v2;
	while (n--) {
		int a; cin >> a;
		v1.emplace_back(a);
	}
	while (m--) {
		int a; cin >> a;
		v2.emplace_back(a);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	vector<int> res;
	set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(res));
	cout << res.size() << '\n';
	for (const auto i : res)cout << i << ' ';
}