#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int arr[100001];
int res[100001];
int near[100001];
int n;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	vector<pi> stack; stack.reserve(n);
	stack.emplace_back(arr[0], 1);
	for (int i = 1; i < n; ++i)
	{
		while (!stack.empty() && stack.back().first <= arr[i])
		{
			stack.pop_back();
		}
		if (!stack.empty())
		{
			near[i] = stack.back().second;
			res[i] += stack.size();
		}
		stack.emplace_back(arr[i], i + 1);
	}
	stack.clear();
	stack.emplace_back(arr[n - 1], n);
	for (int i = n - 2; i >= 0; --i)
	{
		while (!stack.empty() && stack.back().first <= arr[i])
		{
			stack.pop_back();
		}
		if (!stack.empty())
		{
			if (0 == near[i])
			{
				near[i] = stack.back().second;
			}
			else
			{
				const auto a = abs(near[i] - (i + 1));
				const auto b = abs(stack.back().second - (i + 1));
				if (a > b)
				{
					near[i] = stack.back().second;
				}
			}
			res[i] += stack.size();
		}
		stack.emplace_back(arr[i], i + 1);
	}
	for (int i = 0; i < n; ++i)
	{
		cout << res[i];
		if (0 != res[i])
		{
			cout << ' ' << near[i];
		}
		cout << '\n';
	}
}