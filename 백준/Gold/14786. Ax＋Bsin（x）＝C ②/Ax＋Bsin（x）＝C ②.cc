#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b, c; cin >> a >> b >> c;
	// b * sin(x) = c - a*x
	double s = (double)(c - b * 1.) / (double)a;
	double e = (double)(c - b * -1.) / (double)a;
	while (e - s >= 1e-9)
	{
		const auto mid = (s + e) / (double)2.;
		if (sin(mid) > ((double)c - (double)a * mid) / (double)b)
		{
			e = mid;
		}
		else
		{
			s = mid;
		}
	}
	cout << fixed;
	cout.precision(10);
	cout << s;
}