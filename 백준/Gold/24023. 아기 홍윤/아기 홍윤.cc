#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int arr[200001];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; ++i)cin >> arr[i];
	int s = 0;
	int e = 0;
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if (s < 0)s = i;
		if ((k | arr[i]) > k)
		{
			ans = 0;
			s = -1;
		}
		else
		{
			ans |= arr[i];
			if (ans == k)
			{
				e = i;
				break;
			}
		}
	}
	if (ans == k)cout << s + 1 << ' ' << e + 1;
	else cout << -1;
}