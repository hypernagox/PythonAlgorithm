#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
constexpr const int INF = 987654321;
int n;
int arr[100001];
int memo[100001];
int GO(const int last_idx)
{
	if (last_idx == n)return 0;
	auto& ref = memo[last_idx];
	if (-INF != ref)return ref;
	return ref = max(arr[last_idx], GO(last_idx + 1) + arr[last_idx]);
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)cin >> arr[i];
	for (int i = 0; i < n; ++i)memo[i] = -INF;
	int res = -INF;
	for (int i = 0; i < n; ++i)
	{
		res = max(res, GO(i));
	}
	cout << res;
}