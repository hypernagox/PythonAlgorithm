#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
constexpr const int INF = 987654321;
ll dp[31][31]; // 한알짜리 i개 반알짜리 j개일때 가능한 경우의 수
ll sol(const int N, const int W, const int H, const int cur)
{
	if (cur == 2 * N)
	{
		return 1;
	}
	auto& ref = dp[W][H];
	if (ref)return ref;
	if (H > 0)
	{
		// 반개짜리먹음
		ref += sol(N, W, H - 1, cur + 1);
	}
	if (W > 0)
	{
		
		// 한개짜리먹음
		ref += sol(N, W - 1, H + 1, cur + 1);
	}
	return ref;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (;;)
	{
		int x; cin >> x;
		if (0 == x)break;
		cout << sol(x, x, 0, 0) << '\n';
	}
}