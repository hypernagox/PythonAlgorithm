#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
ll memo[1000001];
ll GO(const int n)
{
	auto& ref = memo[n];
	if (-1 != ref)return ref;
	if (n == 1)return ref = 1;
	if (n == 2)return ref = 2;
	return ref = (GO(n - 1) + GO(n - 2)) % 15746;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(memo, -1, sizeof(memo));
	int n; cin >> n;
	cout << GO(n);
}