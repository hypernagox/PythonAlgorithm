#include <bits/stdc++.h>
using namespace std;
double GetDist(const double a, const double b,
			const double x,const double y)
{
	const auto a1 = (a - x) * (a - x);
	const auto a2 = (b - y) * (b - y);
	return sqrt(a1 + a2);
}
double x[4];
double y[4];
int arr[]{ 0,1,2,3 };
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 4; ++i)
	{
		cin >> x[i] >> y[i];
	}
	double res = 987654321;
	do
	{
		double temp = 0;
		for (int i = 0; i < 3; ++i)
		{
			temp += GetDist(
				x[arr[i]],
				y[arr[i]],
				x[arr[i + 1]],
				y[arr[i + 1]]
				);
		}
		res = min(res,temp);
	} while (next_permutation(arr + 1, arr + 4));
	cout << (int)res;
}