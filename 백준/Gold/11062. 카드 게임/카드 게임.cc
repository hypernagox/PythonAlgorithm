#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
constexpr const int INF = 987654321;
int n;
int arr[1001];
int memo[1001][1001][2];
int GO(const int left, const int right,const bool turn)
{
	auto& ref = memo[left][right][turn];
	if (-1 != ref)return ref;
	if (left == right)
	{
		if (turn)return arr[left];
		else return 0;
	}
	int a = 0;
	int b = 0;
	// 근우턴
	if (turn)
	{
		// 왼쪽을 선택
		a = GO(left + 1, right, !turn) + arr[left];

		// 오른쪽을 선택
		b = GO(left, right - 1, !turn) + arr[right];
		return ref = max(a, b);
	}
	// 아니면
	else
	{
		// 딴녀석의 선택
		// 왼쪽을 선택
		a = GO(left + 1, right, !turn);

		// 오른쪽을 선택
		b = GO(left, right - 1, !turn);
		return ref = min(a, b);
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		memset(memo, -1, sizeof(memo));
		for (int i = 0; i < n; ++i)cin >> arr[i];
		cout << GO(0, n - 1, true) << '\n';
	}
}