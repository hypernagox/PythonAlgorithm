#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--)
	{
		int arr[1001]{};
		int n; cin >> n;
		int cnt = 0;
		for (int i = 0; i < n; ++i)cin >> arr[i];
		sort(arr, arr + n);
		arr[n] = -1;
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				const auto diff = arr[j] - arr[i];
				const auto iter = lower_bound(arr + j + 1, arr + n, arr[j] + diff);
				if (*iter == arr[j] + diff)
				{
					++cnt;
				}
			}
		}
		cout << cnt << '\n';
	}
}