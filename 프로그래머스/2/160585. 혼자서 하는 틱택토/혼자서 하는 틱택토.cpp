#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

int solution(vector<string> board)
{
	// 돌 개수
	// 승리 이후 돌개수
	int num_o = 0;
	int num_x = 0;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			num_o += ('O' == board[i][j]);
			num_x += ('X' == board[i][j]);
		}
	}
	if (!(num_o == num_x || num_o == num_x + 1))
	{
		return 0;
	}
	// 행검사
	bool win_o = false;
	bool win_x = false;
	for (int i = 0; i < 3; ++i)
	{
		if ("OOO" == board[i])
		{
			win_o = true;
		}
		else if ("XXX" == board[i])
		{
			win_x = true;
		}
	}
	// 열검사
	for (int i = 0; i < 3; ++i)
	{
		string temp;
		for (int j = 0; j < 3; ++j)
		{
			temp.push_back(board[j][i]);
		}
		if ("OOO" == temp)
		{
			win_o = true;
		}
		else if ("XXX" == temp)
		{
			win_x = true;
		}
	}
	// 대각선
	string temp;
	for (int i = 0; i < 3; ++i)
	{
		temp.push_back(board[i][i]);
	}
	if ("OOO" == temp)
	{
		win_o = true;
	}
	else if ("XXX" == temp)
	{
		win_x = true;
	}
	temp.clear();
	for (int i = 0; i < 3; ++i)
	{
		temp.push_back(board[i][2 - i]);
	}
	if ("OOO" == temp)
	{
		win_o = true;
	}
	else if ("XXX" == temp)
	{
		win_x = true;
	}
	if (win_o && win_x)
	{
		return 0;
	}
	if (win_o)
	{
		return num_o > num_x;
	}
	if (win_x)
	{
		return num_o == num_x;
	}
	return 1;
}