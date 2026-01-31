#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int arr[100001];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; ++i)cin >> arr[i];
	int res = 987654321;
	int s = 0;
	int e = n - 1;
	while (s < e)
	{
		const auto val = arr[e] + arr[s];
		if (val > 0)
		{
			--e;
		}
		else if(val < 0)
		{
			++s;
		}
		else
		{
			res = 0;
			break;
		}
		if (abs(res) > abs(val))res = val;
	}
	cout << res;
}