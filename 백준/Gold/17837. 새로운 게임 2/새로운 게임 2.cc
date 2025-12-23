#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
constexpr const int dy[]{ 0,0,-1,1 };
constexpr const int dx[]{ 1,-1,0,0 };
struct Data
{
	int y, x, dir;
	int num;
};
int n, k;
vector<Data*> board[13][13];
int board_color[13][13];
vector<Data> horse;
void ReverseDir(Data& d)
{
	if (d.dir == 0)
	{
		d.dir = 1;
	}
	else if (d.dir == 1)
	{
		d.dir = 0;
	}
	else if (d.dir == 2)
	{
		d.dir = 3;
	}
	else if (d.dir == 3)
	{
		d.dir = 2;
	}
}
vector<Data*> FindHorse(const int y,const int x,const int target)
{
	int idx = 0;
	for (int i = 0; i < board[y][x].size(); ++i)
	{
		if (board[y][x][i]->num == target)
		{
			idx = i;
			break;
		}
	}
	vector<Data*> temp;
	for (int i = idx; i < board[y][x].size(); ++i)
	{
		temp.emplace_back(board[y][x][i]);
	}
	const auto N = board[y][x].size();
	for (int i = 0; i < N - idx; ++i)
	{
		board[y][x].pop_back();
	}
	return temp;
}
bool IsFinish()
{
	for (const auto& i : board)
	{
		for (const auto& j : i)
		{
			if (j.size() >= 4)return true;
		}
	}
	return false;
}
int GO()
{
	int turn = 0;
	for (;;)
	{
		++turn;
		if (turn > 1000)return -1;
		for (int i = 0; i < horse.size(); ++i)
		{
			auto& d = horse[i];
			const auto cur_y = d.y;
			const auto cur_x = d.x;
			bool flag = true;
		RE:
			const auto ny = d.y + dy[d.dir];
			const auto nx = d.x + dx[d.dir];
			// 넘어갔다면
			if (ny < 0 || nx < 0 || ny >= n || nx >= n)
			{
				if (flag)
				{
					ReverseDir(d);
					flag = false;
					goto RE;
				}
			}
			// 파란색이라면
			else if (board_color[ny][nx] == 2)
			{
				if (flag)
				{
					ReverseDir(d);
					flag = false;
					goto RE;
				}
			}
			else
			{
				auto temp = FindHorse(d.y, d.x, d.num);
				// 빨간색 규칙 적용
				if (board_color[ny][nx] == 1)
				{
					reverse(temp.begin(), temp.end());
				}
				for (const auto d : temp)
				{
					d->y = ny;
					d->x = nx;
					board[ny][nx].emplace_back(d);
				}
				if (board[ny][nx].size() >= 4)return turn;
			}
		}
	}
	return turn;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> board_color[i][j];
		}
	}
	horse.reserve(k + 1);
	for (int i = 0; i < k; ++i)
	{
		int a, b, c; cin >> a >> b >> c;
		horse.emplace_back(a - 1, b - 1, c - 1, i);
		board[a - 1][b - 1].emplace_back(&horse.back());
	}
	cout << GO();
}