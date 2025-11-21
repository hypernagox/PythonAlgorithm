#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vector<ll> v;
	for (int i = 0; i < n; ++i)
	{
		ll x; cin >> x; v.emplace_back(x);
	}
	sort(v.begin(), v.end());
	ll res = 0;
	for (int i = 1; i < n - 1; ++i)
	{
		// | a + c - 2b |
		// 2b - (a+c)
		const auto d1 = llabs(v[n - 1] + v[i - 1] - v[i] * 2);
		const auto d2 = llabs(v[0] + v[i + 1] - v[i] * 2);
		res = max({ res,d1,d2 });
	}
	cout << res;
}