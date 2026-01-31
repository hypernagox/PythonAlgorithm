#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
ll arr[1001];
vector<ll> s;
int n;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)cin >> arr[i];
	sort(arr, arr + n);
	s.reserve(n * n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 0; j < n; ++j)
		{
			s.emplace_back(arr[i] + arr[j]);
		}
	}
	sort(s.begin(), s.end());
	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = i; j >= 0; --j)
		{
			const auto target = arr[i] - arr[j];
			if (binary_search(s.begin(), s.end(), target))
			{
				cout << arr[i];
				return 0;
			}
		}
	}
}