#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
ll memo[101][101][101];
ll w(const ll a, const ll b, const ll c)
{
	auto& ref = memo[a + 50][b + 50][c + 50];
	if (-1 != ref)return ref;
	if (a <= 0 or b <= 0 or c <= 0) return ref = 1;
	if (a > 20 or b > 20 or c > 20)return ref = w(20, 20, 20);
	if (a < b and b < c)return ref = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	return ref = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(memo, -1, sizeof(memo));
	for (;;)
	{
		int a, b, c; cin >> a >> b >> c;
		if ((a & b & c) == -1)break;
		//cout << format("w({}, {}, {}) = {}\n", a, b, c, w(a, b, c));
		printf("w(%d, %d, %d) = %lld\n", a, b, c, w(a, b, c));
	}
}