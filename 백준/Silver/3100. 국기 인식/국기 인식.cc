#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
constexpr const int MAX_VAL = 987654321;
string mat[6];
int KeepRowChar(const int i1, const int ch)
{
	int cnt = 0;
	for (int i = i1; i < i1 + 2; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cnt += (mat[i][j] - 'A' == ch);
		}
	}
	return cnt;
}
int KeepColChar(const int i1, const int ch)
{
	int cnt = 0;
	for (int i = 0; i < 6; ++i)
	{
		for (int j = i1; j < i1 + 3; ++j)
		{
			cnt += (mat[i][j] - 'A' == ch);
		}
	}
	return cnt;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	map<char, int> m;
	for (auto& i : mat)
	{
		cin >> i;
		for (const auto ch : i)++m[ch];
	}
	int bestKeepH = 0;
	for (int b = 0; b < 26; ++b)
	{
		int bestTop = 0;
		int bestBot = 0;
		for (int a = 0; a < 26; ++a)
		{
			if (a == b) continue;
			bestTop = max(bestTop, KeepRowChar(0, a));
		}
		for (int c = 0; c < 26; ++c)
		{
			if (c == b) continue;
			bestBot = max(bestBot, KeepRowChar(4, c));
		}
		const int midKeep = KeepRowChar(2, b);
		bestKeepH = max(bestKeepH, bestTop + midKeep + bestBot);
	}
	const int ansH = 54 - bestKeepH;
	int bestKeepV = 0;
	for (int b = 0; b < 26; ++b)
	{
		int bestLeft = 0;
		int bestRight = 0;
		for (int a = 0; a < 26; ++a)
		{
			if (a == b) continue;
			bestLeft = max(bestLeft, KeepColChar(0, a));
		}
		for (int c = 0; c < 26; ++c)
		{
			if (c == b) continue;
			bestRight = max(bestRight, KeepColChar(6, c));
		}
		const int midKeep = KeepColChar(3, b);
		bestKeepV = max(bestKeepV, bestLeft + midKeep + bestRight);
	}
	const int ansV = 54 - bestKeepV;
	cout << min(ansH, ansV);
}