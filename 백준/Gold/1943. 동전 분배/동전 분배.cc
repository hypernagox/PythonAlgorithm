#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
bool flag = false;
set<int> visited;
void GO(const long long target_val,vector<pi>& coins, const long long cur_val = 0)
{
	if (cur_val == target_val)
	{
		flag = true;
		return;
	}
	if (!visited.emplace(cur_val).second)return;
	for (int i = 0; i < coins.size(); ++i)
	{
		if (coins[i].second == 0)continue;
		--coins[i].second;
		GO(target_val, coins, cur_val + coins[i].first);
		++coins[i].second;
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<pi> coins;
	for (int i = 0; i < 3; ++i)
	{
		long long sum = 0;
		int n; cin >> n;
		for (int j = 0; j < n; ++j)
		{
			int coin, cnt; cin >> coin >> cnt;
			sum += coin * cnt;
			coins.emplace_back(coin, cnt);
		}
		if (sum % 2 != 0)
		{
			cout << 0 << '\n';
			continue;
		}
		const auto target_val = sum / 2;
		GO(target_val, coins);
		if (flag)cout << 1 << '\n';
		else cout << 0 << '\n';
		flag = false;
		visited.clear();
		coins.clear();
	}
}