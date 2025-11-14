#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> v;
long long target = 0;
bool Check(const int mid)
{
	long long s = 0;
	for (const auto i : v)
	{
		s += min(i, mid);
	}
	return target <= s;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int x; cin >> x;
			target += x;
			v.emplace_back(x);
		}
	}
	int cnt = 0;
	if (target & 1)++cnt;
	target /= 2;
	target += cnt;
	int l = 0;
	int r = 987654321;
	while (l < r)
	{
		const auto mid = (l + r) / 2;
		if (Check(mid))
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	cout << l;
}