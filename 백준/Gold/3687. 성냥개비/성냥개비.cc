#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
constexpr const long long needs[] = { 6,2,5,5,4,5,6,3,7,6 };
constexpr const long long num[]{ 1<<20,1<<20,1,7,4,2,0,8}; // 수를 늘려나갈 때 쓸거
long long dp[102];
long long n;
void MakeMin()
{
	for (int i = 0; i < 8; ++i)dp[i] = num[i];
	dp[6] = 6; // 0은안됨
	dp[8] = 10;
	for (int i = 9; i <= n; ++i)
	{
		dp[i] = 9e18;
		for (int j = 2; j <= 7; ++j)
		{
			dp[i] = min(dp[i], dp[i - j] * 10LL + num[j]); // i - j에서의 최솟값에서 자리수를 하나 늘려주고 1의자리를 채운다
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	n = 101;
	MakeMin();
	while (t--)
	{
		cin >> n;
		cout << dp[n] << ' ';
		auto num_of_one = n / 2;
		if (n & 1)
		{
			--num_of_one;
			cout << 7;
		}
		for (int i = 0; i < num_of_one; ++i)cout << 1;
		cout << '\n';
	}
}