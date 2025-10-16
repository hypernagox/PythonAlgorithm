#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// n H r -> n + r - 1 C r - 1
	// 9 C 2
	int k, n; cin >> k >> n;
	const auto N = n - k + k - 1;
	const auto K = min(k - 1, N - k + 1);
	size_t a = 1;
	size_t b = 1;
	for (int i = K; i >= 1; --i)
	{
		a *= (N - (K - i));
		b *= i;
	}
	cout << a / b;
}