#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
constexpr const int INF = 987654321;
int N;
int memo[101][10];
int GO(const int n, const int last)
{
	if (n == N)return 1;
	auto& ref = memo[n][last];
	if (ref)return ref;
	int a = 0;
	if (last == 0)
	{
		a += GO(n + 1, 1);
	}
	else if (last == 9)
	{
		a += GO(n + 1, 8);
	}
	else
	{
		a += GO(n + 1, last - 1) + GO(n + 1, last + 1);
	}
	return ref = a % 1000000000;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	int res = 0;
	for (int i = 1; i <= 9; ++i)
	{
		res = (res + GO(1, i)) % 1000000000;
	}
	cout << res;
}