#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<int> v1, v2;
	int n, m;
	cin >> n;
	v1.reserve(n);
	while (n--)
	{
		int a; cin >> a; v1.emplace_back(a);
	}
	cin >> m;
	v2.reserve(m);
	while (m--)
	{
		int a; cin >> a; v2.emplace_back(a);
	}
	sort(v1.begin(), v1.end());
	for (const auto i : v2)
	{
		cout << binary_search(v1.begin(), v1.end(), i) << ' ';
	}
}