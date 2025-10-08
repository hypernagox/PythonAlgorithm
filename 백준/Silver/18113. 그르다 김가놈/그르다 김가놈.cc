#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
bool Check(const vector<int>& gimbob,const int gimbob_len, const int gimbob_count)
{
	int cnt = 0;
	for (int i = 0; i < gimbob.size(); ++i)
	{
		cnt += (gimbob[i] / gimbob_len);
	}
	return cnt >= gimbob_count;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k, m; cin >> n >> k >> m;
	//int l = 1;
	//int r = 1 << 20;
	vector<int> v;
	for (int i = 0; i < n; ++i) 
	{
		int x; cin >> x;
		if (x >= 2 * k)x -= 2 * k;
		else if (x >= k)x -= k;
		else x = 0;
		v.emplace_back(x);
	}
	int l = 1; int h = 1000000000;
	int result = -1;
	while (l <= h) {
		int mid = (l + h) / 2;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			cnt += v[i] / mid;
		}
		if (m > cnt) {
			h = mid - 1;
		}
		else {
			result = mid;
			l = mid + 1;
		}
	}
	cout << result;
}