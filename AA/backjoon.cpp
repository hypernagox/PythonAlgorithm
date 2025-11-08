#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int* f1();
int& f2();
const int& f3();
int main()
{
	auto a = f1();
	auto b = f2();
	auto c = f3();
	ios::sync_with_stdio(false); cin.tie(NULL);
	int t, n; cin >> n >> t;
	vector<ll> vp, vm;
	while (t--)
	{
		vp.clear(); vm.clear();
		bool flag = false;
		bool used = false;
		for (int i = 0; i < n; ++i)
		{
			int x; cin >> x;
			if (x < 0)
			{
				vm.emplace_back(x);
			}
			else if (x > 0)
			{
				vp.emplace_back(x);
				used = true;
			}
			else
			{
				flag = true;
			}
		}
		sort(vm.begin(), vm.end(), greater<ll>{});
		ll res = 1;
		while (vm.size() >= 2)
		{
			const auto a1 = vm.back();
			vm.pop_back();
			const auto a2 = vm.back();
			vm.pop_back();
			res *= (a1 * a2);
			used = true;
		}
		for (const auto i : vp)res *= i;
		if (!used)
		{
			if (flag)
			{
				cout << 0 << '\n';
			}
			else
			{
				cout << vm.front() << '\n';
			}
		}
		else
		{
			cout << res << '\n';
		}
	}
}