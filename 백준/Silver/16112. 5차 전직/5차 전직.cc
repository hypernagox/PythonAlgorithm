#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	vector<ll> v;
	for (int i = 0; i < n; ++i)
	{
		ll x; cin >> x;
		v.emplace_back(x);
	}
	sort(v.begin(), v.end());
	int cur_k = 0;
	ll res = 0;
	for (int i = 0; i < n; ++i)
	{
		res += (cur_k * v[i]);
		cur_k = min(cur_k + 1, k);
	}
	cout << res;
}