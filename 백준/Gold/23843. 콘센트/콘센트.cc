#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int arr[10001];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	priority_queue<int,vector<int>,greater<int>> pq;
	for (int i = 0; i < n; ++i)cin >> arr[i];
	for (int i = 0; i < m; ++i)pq.emplace(0);
	sort(arr, arr + n, greater<int>{});
	int res = 0;
	for (int i = 0; i < n; ++i)
	{
		const auto end_time = pq.top() + arr[i];
		pq.pop();
		pq.emplace(end_time);
		res = max(res, end_time);
	}
	cout << res;
}
