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
	int l = 1;
	int r = 1;
	vector<int> gimbob;
	for (int i = 0; i < n; ++i) 
	{
		int x; cin >> x;
		if (x >= 2 * k)x -= 2 * k;
		else if (x >= k)x -= k;
		else x = 0;
		r = max(r, x);
		gimbob.emplace_back(x);
	}
    ++r;
	int ans = -1;
	while (l < r)
	{
		const int mid = (l + r) / 2;
		if (Check(gimbob, mid,m))
		{
			ans = max(ans, mid);
			l = mid + 1;
		}
		else
		{
			r = mid;
		}
	}
	cout << ans;
}