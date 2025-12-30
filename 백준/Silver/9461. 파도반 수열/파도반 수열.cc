#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
ll memo[101];
ll GO(const int n)
{
	auto& ref = memo[n];
	if (ref)return ref;
	if (n == 1 || n == 2 || n == 3)return ref = 1; 
	if (n == 4 || n == 5)return ref = 2;
	return ref = GO(n - 1) + GO(n - 5);
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	while (n--)
	{
		int x; cin >> x;
		cout << GO(x) << '\n';
	}
}