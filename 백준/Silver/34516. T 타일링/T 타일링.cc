#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	if (N % 4 != 0) 
	{
		cout << -1;
		return 0;
	}
	const string p[4] = 
	{
		"daaa",
		"ddab",
		"dcbb",
		"cccb"
	};
	const int k = N / 4;
	for (int blockRow = 0; blockRow < k; ++blockRow) 
	{
		for (int r = 0; r < 4; ++r)
		{
			for (int blockCol = 0; blockCol < k; ++blockCol) 
			{
				cout << p[r];
			}
			cout << '\n';
		}
	}
}