#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
bool Check(const vector<int>& items, const ll human, const ll mid)
{
	ll cur_human = 0;
	for (const auto i : items)
	{
		// mid개로 배분이 되나?
		const auto h = (i + (mid - 1)) / mid; // mid개로 균등배분
		cur_human += h;
	}
	return cur_human <= human;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	vector<int> items;
	for (int i = 0; i < m; ++i)
	{
		int x; cin >> x;
		items.emplace_back(x);
	}
	ll s = 1;
	ll e = numeric_limits<int>::max();
	while (s < e)
	{
		const auto mid = (s + e) / 2;
		if (Check(items,n,mid))
		{
			e = mid;
		}
		else
		{
			s = mid + 1;
		}
	}
	cout << s;
}
