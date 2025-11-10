#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
vector<ll> res;
void GO(const ll cur, const ll last)
{
	res.emplace_back(cur);
	for (int i = 0; i < last; ++i)
	{
		GO(cur * 10 + i, i);
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i <= 9; ++i)
	{
		GO(i, i);
	}
	sort(res.begin(), res.end());
	if (res.size() < n)cout << -1;
	else cout << res[n - 1];
}