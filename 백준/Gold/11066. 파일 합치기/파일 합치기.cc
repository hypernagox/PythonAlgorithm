#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
constexpr const int INF = 987654321;
int T;
int arr[501];
int psum[501];
int memo[501][501];
int S(const int l, const int r)
{
	return psum[r + 1] - psum[l];
}
int GO(const int l, const int r)
{
	if (l >= r)return 0;
	auto& ref = memo[l][r];
	if (-1 != ref)return ref;
	int res = INF;
	for (int k = l; k < r; ++k)
	{
		const auto a = GO(l, k);
		const auto b = GO(k + 1, r);
		res = min(res, (a + b) + S(l, r));
	}
	return ref = res;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		int n; cin >> n;
		memset(memo, -1, sizeof(memo));
		for (int i = 0; i < n; ++i) 
		{
			cin >> arr[i];
			psum[i + 1] = arr[i] + psum[i];
		}
		cout << GO(0, n - 1) << '\n';
	}
}