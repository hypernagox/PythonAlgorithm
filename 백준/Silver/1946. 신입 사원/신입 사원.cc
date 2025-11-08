#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
pi arr[100001];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i].first >> arr[i].second;
		}
		sort(arr, arr + n);
		int res = 1;
		int min_rank = arr[0].second;
		for (int i = 1; i < n; ++i)
		{
			if (min_rank > arr[i].second)
			{
				min_rank = arr[i].second;
				++res;
			}
		}
		cout << res << '\n';
	}
}