#include <bits/stdc++.h>
using namespace std;
int n;
int arr[200001];
multiset<int> bags;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		bags.emplace(x);
	}
	vector<int> res;
	for (int i = 0; i < n; ++i)
	{
		const auto it = bags.lower_bound(arr[i]);
		if (bags.end() == it)
		{
			cout << -1;
			return 0;
		}
		else
		{
			res.emplace_back(*it);
			bags.erase(it);
		}
	}
	for (const auto i : res)cout << i << ' ';
}