#include <bits/stdc++.h>
#include <ranges>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
struct Data
{
	//bool is_alive = true;
	int life = -1;
	const auto operator<(const Data& d)const {
		return life < d.life;
	}
};
vector<Data> board[11][11];
int ground_energy[11][11];
int plus_energy[11][11];
int cur_tree[11][11];
int n, m, k;
constexpr const int dy[]{ -1,-1,0,1,1,1,0,-1 };
constexpr const int dx[]{ 0,1,1,1,0,-1,-1,-1 };
void GO()
{
	int turn = 0;
	vector<Data> temp[11][11];
	for (;;)
	{
		if (turn == k)
		{
			int cnt = 0;
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j) 
				{
					cnt += board[i][j].size();
				}
			}
			cout << cnt;
			break;
		}
		// 봄
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				sort(board[i][j].begin(),board[i][j].end());
				for (auto it = board[i][j].begin(); it != board[i][j].end();)
				{
					// 자신의 나이만큼 에너지를 먹고
					auto& d = *it;
					if (d.life <= ground_energy[i][j])
					{
						ground_energy[i][j] -= d.life;
						// 나이를 올림
						const_cast<Data&>(d).life++;
						++it;
					}
					else
					{
						const auto idx = it - board[i][j].begin();
						auto N = board[i][j].size() - idx;
						while (N--)
						{
							ground_energy[i][j] += board[i][j].back().life / 2;
							board[i][j].pop_back();
						}
						//auto it2 = it;
						//for (it; it != board[i][j].end();)
						//{
						//	//++it;
						//	if (it == board[i][j].end())break;
						//	board[i][j].pop_back();
						//	if (it == board[i][j].end())break;
						//	//++it;
						//}
						//auto N = board[i][j].end() - it;
						//while (N--)
						//{
						//	
						//}
						//for (auto it2 = it; it2 != board[i][j].end();)
						//{
						//	ground_energy[i][j] += it2->life / 2;
						//	it2 = board[i][j].erase(it2);
						//	cur_tree[i][j]--;
						//}
						it = board[i][j].end();
						break;
						//const_cast<Data&>(d).is_alive = false;
						//cur_tree[i][j]--;
					}
				}
			}
		}
		// 여름
		//for (int i = 0; i < n; ++i)
		//{
		//	for (int j = 0; j < n; ++j)
		//	{
		//		for (auto it = board[i][j].begin(); it != board[i][j].end();)
		//		{
		//			// 봄에죽은 나무는 양분으로
		//			if (!it->is_alive)
		//			{
		//				ground_energy[i][j] += it->life / 2;
		//				it = board[i][j].erase(it);
		//				//cur_tree[i][j]--;
		//			}
		//			else
		//			{
		//				++it;
		//			}
		//		}
		//	}
		//}
		// 가을
		//int temp[11][11]{ 0 };
		
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				//int temp[11][11]{ 0 };
				//auto b = board[i][j].begin();
				//int cnt = 0;
				//for (int a = 0; a < cur_tree[i][j]; ++a)
				for(const auto& d:board[i][j])
				{
					//auto& d = *b++;
					//if (!d.is_alive)
					//{
					//	ground_energy[i][j] = b->life / 2;
					//	b = board[i][j].erase(b);
					//	//ground_energy[i][j] += it->life / 2;
					//	//board[i][j].erase(it);
					//	//cur_tree[i][j]--;
					//	continue;
					//}
					if (d.life % 5 == 0)
					{
						for (int k = 0; k < 8; ++k)
						{
							const auto ny = i + dy[k];
							const auto nx = j + dx[k];
							if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
						//	temp[ny][nx]++;
							temp[ny][nx].emplace_back(1);
							//++cnt;
						}
					}
				}
				//cur_tree[i][j] += cnt;
				ground_energy[i][j] += plus_energy[i][j];
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j) 
			{
				for (const auto d : temp[i][j])
				{
					board[i][j].emplace_back(d);
				}
				temp[i][j].clear();
				//board[i][j].merge(move(temp[i][j]));
				//cur_tree[i][j] += temp[i][j];
			}
		}
		// 겨울
		//for (int i = 0; i < n; ++i)
		//{
		//	for (int j = 0; j < n; ++j)
		//	{
		//		ground_energy[i][j] += plus_energy[i][j];
		//	//	board[i][j].sort();
		//	//	sort(board[i][j].begin(), board[i][j].end());
		//	}
		//}
		++turn;
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	//for (auto& i : board)for (auto& j : i) {
	//	j.is_alive = false;
	//}
	for (auto& i : ground_energy)for (auto& j : i) {
		j = 5;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> plus_energy[i][j];
		}
	}
	for (int i = 0; i < m; ++i)
	{
		int a, b, c; cin >> a >> b >> c;
		board[a - 1][b - 1].emplace_back( c);
		cur_tree[a - 1][b - 1]++;
	}
	GO();
}