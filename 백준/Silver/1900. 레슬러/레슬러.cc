#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
struct Data
{
	int num;
	int power;
	int magic;
	int win_count = 0;
	const bool CanWin(const Data& d)const noexcept {
		const auto p1 = power + (magic * d.power);
		const auto p2 = d.power + (d.magic * power);
		return p1 > p2;
	}
	const auto operator<(const Data& d)const noexcept {
		if (win_count == d.win_count)
		{
			return CanWin(d);
		}
		return win_count > d.win_count;
	}
};
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vector<Data> v;
	for (int i = 1; i <= n; ++i)
	{
		int a, b; cin >> a >> b;
		v.emplace_back(i, a, b);
	}
	for (int i = 0; i < v.size(); ++i)
	{
		auto& player = v[i];
		for (int j = 0; j < v.size(); ++j)
		{
			if (i == j)continue;
			player.win_count += player.CanWin(v[j]);
		}
	}
	sort(v.begin(), v.end());
	for (const auto& p : v)cout << p.num << '\n';
}