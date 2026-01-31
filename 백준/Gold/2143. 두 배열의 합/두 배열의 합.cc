#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int arr1[1001];
int arr2[1001];
int n, m;
int t;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	cin >> n;
	vector<ll> s1, s2;
	for (int i = 0; i < n; ++i)cin >> arr1[i];
	cin >> m;
	for (int i = 0; i < m; ++i)cin >> arr2[i];
	ull res = 0;
	for (int i = 0; i < n; ++i)
	{
		ll s = 0;
		for (int j = i; j < n; ++j)
		{
			s += arr1[j];
			s1.emplace_back(s);
		}
	}
	for (int i = 0; i < m; ++i)
	{
		ll s = 0;
		for (int j = i; j < m; ++j)
		{
			s += arr2[j];
			s2.emplace_back(s);
		}
	}
	sort(s2.begin(), s2.end());
	for (const auto i : s1)
	{
		const auto target = t - i;
		const auto [lb, up] = equal_range(s2.begin(), s2.end(), target);
		res += (up - lb);
	}
	cout << res;
}
