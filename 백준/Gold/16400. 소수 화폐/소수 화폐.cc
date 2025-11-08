#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
bool IsPrime[40001];
int dp[40001];
constexpr const int MOD = 123456789;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<int> primes;
	memset(IsPrime, 1, sizeof(IsPrime));
	IsPrime[0] = IsPrime[1] = 0;
	for (int i = 2; i <= sqrt(n); ++i)
	{
		for (int j = i * 2; j <= n; j += i)
		{
			IsPrime[j] = false;
		}
	}
	for (int i = 2; i <= n; ++i)if (IsPrime[i])primes.emplace_back(i);
	dp[0] = 1;
	for (const auto prime : primes)
	{
		for (int i = prime; i <= n; ++i)
		{
			dp[i] = (dp[i] + dp[i - prime]) % MOD;
		}
	}
	cout << dp[n];
}