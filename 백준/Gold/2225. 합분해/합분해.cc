#include <bits/stdc++.h>
using namespace std;
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
constexpr const int INF = static_cast<int>(1e9) + 1;
constexpr const int MIN_INF = -INF;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
ll memo[201][201];
ll GO(const int n, const int k)
{
	if (k == 0)return n == 0;
	auto& ref = memo[n][k];
	if (~ref)return ref;
	ll res = 0;
	for (int i = 0; i <= n; i++)
	{
		res += GO(n - i, k - 1);
		res %= 1000000000;
	}
	return ref = res;
}
void Solve() noexcept
{
	int n, k; cin >> n >> k;
	memset(memo, -1, sizeof(memo));
	cout << GO(n, k);
}
int main()
{
    FastIO();
    Solve();
}