#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	priority_queue<ll> pq;
	ll cur_money = 0;
	for (int i = 0; i < n; ++i)
	{
		ll lim, price; cin >> lim >> price;
		if (lim >= cur_money)
		{
			cur_money += price;
			pq.emplace(price);
		}
		else
		{
			if (!pq.empty())
			{
				// 혹시 제일큰거 하나 버리면 살릴 수 있나?
				if (lim >= cur_money - pq.top() && pq.top() > price)
				{
					cur_money = cur_money - pq.top() + price;
					pq.pop();
					pq.emplace(price);
				}
				else
				{
					// 불가
				}
			}
		}
	}
	if(n==1)cout << "Kkeo-eok";
	else if (pq.size() >= n - 1)cout << "Kkeo-eok";
	else cout << "Zzz";
}