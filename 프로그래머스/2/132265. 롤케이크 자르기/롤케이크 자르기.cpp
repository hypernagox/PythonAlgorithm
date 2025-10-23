#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int solution(vector<int> topping)
{
	int ans = 0;
	map<int, int> m1, m2;
	for(const auto i: topping)
	{
		m2[i]++;
	}
	for (int i = 0; i < topping.size(); ++i)
	{
		const auto t = topping[i];
		m1[t]++;
		const auto iter = m2.find(t);
		iter->second--;
		if (iter->second == 0)
		{
			m2.erase(iter);
		}
		ans += (m1.size() == m2.size());
	}
	return ans;
}