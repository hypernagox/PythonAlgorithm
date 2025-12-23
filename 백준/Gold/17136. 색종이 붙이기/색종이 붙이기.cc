#include <iostream>
#include <algorithm>
using namespace std;
int map[10][10];
int paper[5]{ 5,5,5,5,5 };
int res = 100;
bool check(int y,int x,int size)
{
	for (int i = y; i <= y + size; ++i) {
		for (int j = x; j <= x + size; ++j) {
			if (!map[i][j])
				return false;
		}
	}
	return true;
}
void fiilPaper(int y, int x,int size, int val)
{
	for (int i = y; i <= y + size; ++i) {
		for (int j = x; j <= x + size; ++j) {
			map[i][j] = val;
		}
	}
}
bool isOk(int y, int x)
{
	if (x >= 10 || y >= 10)
		return false;
	return true;
}
bool isFinish()
{
	for (auto& i : map) {
		for (auto& j : i) {
			if (j)
				return false;
		}
	}
	return true;
}
void dfs(int cnt)
{
	if (res < cnt)
		return;
	if (isFinish()) {
		res = min(res, cnt);
		return;
	}
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (map[i][j]) {
				for (int k = 4; k >= 0; --k) {
					if (paper[k] > 0 && check(i, j, k) && isOk(i + k, j + k)) {
						--paper[k];
						fiilPaper(i, j, k, 0);
						dfs(cnt + 1);
						++paper[k];
						fiilPaper(i, j, k, 1);
					}
				}
				return;
			}
		}
	}
}
int main()
{
	for (auto& i : map) {
		for (auto& j : i)
			cin >> j;
	}
	dfs(0);
	res = 100==res ? -1 : res;
	cout << res << '\n';
}