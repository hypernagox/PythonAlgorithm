#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
int dp[1001];
int arr[1001];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
	}
	dp[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		int max_val = 0;
		for (int j = i - 1; j >= 1; --j)
		{
			if (arr[j] < arr[i])
			{
				if (dp[j] > max_val)
				{
					max_val = dp[j];
				}
			}
		}
		dp[i] = max_val + 1;
	}
	cout << *max_element(dp + 1, dp + n + 1);
}