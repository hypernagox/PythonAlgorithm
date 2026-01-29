#include <bits/stdc++.h>
using namespace std;
bool IsPrime[2000001];
constexpr const int LIMIT = 2000000;
void Init()
{
	fill(IsPrime, IsPrime + 2000001, 1);
	IsPrime[0] = IsPrime[1] = 0;
	for (int i = 2; i <= sqrt(2000000); ++i)
	{
		if (!IsPrime[i])continue;
		for (int j = i * i; j <= 2000000; j += i)
		{
			IsPrime[j] = 0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Init();
	int N, M;
	cin >> N >> M;

	for (int k = 2; k <= N + 1; ++k)
	{
		cout << 1LL * k * M << ' ';
	}
}