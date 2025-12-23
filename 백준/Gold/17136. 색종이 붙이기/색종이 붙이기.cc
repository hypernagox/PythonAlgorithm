#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int paper[10][10];
int capacity[5]{ 5,5,5,5,5 };
bool IsOk(const int y, const int x)
{
	if (y < 0 || x < 0 || y >= 10 || x >= 10)return false;
	return true;
}
bool Check(const int y,const int x, const int size)
{
	for (int i = y; i < y + size; ++i)
	{
		for (int j = x; j < x + size; ++j)
		{
			if (!IsOk(i, j))return false;
			if (0 == paper[i][j])return false;
		}
	}
	return true;
}
void FillPaper(const int y, const int x, const int size, const int on_off)
{
	for (int i = y; i < y + size; ++i)
	{
		for (int j = x; j < x + size; ++j)
		{
			paper[i][j] = on_off;
		}
	}
}
bool IsFinish()
{
	for (auto& i : paper)for (auto& j : i)if (j)return false;
	return true;
}
int res = 987654321;
void GO(const int cnt = 0)
{
	if (IsFinish())
	{
		res = min(res, cnt);
		return;
	}
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (paper[i][j])
			{
				for (int size = 1; size <= 5; ++size)
				{
					// 사이즈별로 붙여봄
					if (Check(i, j, size) && capacity[size - 1])
					{
						FillPaper(i, j, size, 0);
						capacity[size - 1]--;
						GO(cnt + 1);
						capacity[size - 1]++;
						FillPaper(i, j, size, 1);
					}
				}
				return;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (auto& i : paper)for (auto& j: i)cin >> j;
	GO();
	if (res == 987654321)cout << -1;
	else cout << res;
}