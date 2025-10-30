#include <iostream>
#include <algorithm>
using namespace std;
int sudoku[9][9];
pair<int, int> nokori[81];
int cnt;
bool Check(int r,int c)
{
	for (int i = 0; i < 9; ++i) {
		if (sudoku[r][c] == sudoku[r][i] && c != i)return false;
		if (sudoku[r][c] == sudoku[i][c] && r != i)return false;
	}
	const int ry = (r / 3) * 3;
	const int rx = (c / 3) * 3;
	for (int y = ry; y < ry + 3; ++y) {
		for (int x = rx; x < rx + 3; ++x) {
			if (r == y && x == c)continue;
			if (sudoku[r][c] == sudoku[y][x])return false;
		}
	}
	return true;
}
void go(int n = 0)
{
	if (n == cnt) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				cout << sudoku[i][j] << ' ';
			}
			cout << '\n';
		}
		exit(0);
	}
	const auto [y, x] = nokori[n];
	for (int j = 1; j <= 9; ++j) {
		sudoku[y][x] = j;
		if (Check(y, x))
			go(n + 1);
	}
	sudoku[y][x] = 0;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			int c; cin >> c;
			if (c==0)
				nokori[cnt++] = { i,j };
			else
				sudoku[i][j] = c;
		}
	}
	go();
}