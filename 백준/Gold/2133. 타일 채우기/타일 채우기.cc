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
int memo[31];
int GO(const int n)
{
	if (n == 0) return 1;
	if (n == 1) return 0;
	if (n == 2) return 3;
	if (memo[n] != 0) return memo[n];
	int result = 3 * GO(n - 2);
	for (int i = 3; i <= n; i++) 
	{
		if (i % 2 == 0)
		{
			result += 2 * GO(n - i);
		}	
	}
	return memo[n] = result;
}
void Solve() noexcept
{
	int n; cin >> n;
	cout << GO(n);
}
int main()
{
    FastIO();
    Solve();
}