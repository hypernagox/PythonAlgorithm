#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int n;
struct Data
{
	ll dead_line;
	ll require_time;
	const auto operator<(const Data& d)const noexcept {
		if (dead_line == d.dead_line)return require_time < d.require_time;
		return dead_line < d.dead_line;
	}
};
vector<Data> v;
bool Check(const ll mid)
{
	ll cur_time = mid;
	for (const auto [d, r] : v)
	{
		cur_time += r;
		if (d < cur_time)
		{
			return false;
		}
		//else
		//{
		//	cur_time += r;
		//}
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		Data d;
		cin >> d.require_time >> d.dead_line;
		//d.dead_line -= d.require_time;
		v.emplace_back(d);
	}
	sort(v.begin(), v.end());
	long long l = 0;
	long long r = v.back().dead_line;
	long long res = -1;
	//for (int i = 0; i < r; ++i)
	//{
	//	if (!Check(i))
	//	{
	//		res = i - 1;
	//		break;
	//	}
	//}
	while (l < r)
	{
		const auto mid = (l + r) / 2;
		if (Check(mid))
		{
			res = max(res, mid);
			l = mid + 1;
		}
		else
		{
			r = mid;
		}
	}
	cout << res;
}