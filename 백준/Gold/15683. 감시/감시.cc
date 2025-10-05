#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
constexpr const int dy[]{ -1,0,1,0 };
constexpr const int dx[]{ 0,1,0,-1 };
enum DIR
{
	UP = 0,
	RIGHT = 1,
	DOWN = 2,
	LEFT = 3,

	END
};
int n, m;
void SpreadCCTV(vector<vector<char>>& room, pair<int, int> cur_dir, int y,int x)
{
	const auto ny = y + cur_dir.first;
	const auto nx = x + cur_dir.second;
	if (ny < 0 || nx < 0 || ny >= n || nx >= m)return;
	if (room[ny][nx] == 6)return;
	if (room[ny][nx] == 0)
	{
		room[ny][nx] = '#';
	}
	SpreadCCTV(room, cur_dir, ny, nx);
}
struct CCTV
{
	vector<int> dirs;
	int ypos, xpos;
	pair<int, int> Rotate(const int y, const int x) {
		return make_pair(x, -y);
	}
	void ApplyRotate(const int i, vector<vector<char>>& room) {
		// 90도 회전 x,y -> y,-x
		for (const auto dir : dirs)
		{
			pair<int, int> cur_dir = make_pair(dy[dir], dx[dir]);
			for (int k = 0; k < i; ++k)
			{
				cur_dir = Rotate(cur_dir.first, cur_dir.second);
			}
			SpreadCCTV(room, cur_dir, ypos, xpos);
		}
	}
};
vector<CCTV> cctvs;
int ans = 1 << 20;
void GO(const int cur_cctv,vector<vector<char>>& room)
{
	if (cctvs.size() == cur_cctv)
	{
		// 사각지대 체크
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j) 
			{
				if (0 == room[i][j])
				{
					++sum;
				}
			}
		}
		ans = min(ans, sum);
		return;
	}
	for (int i = 0; i < 4; ++i)
	{
		auto prev_room = room;
		cctvs[cur_cctv].ApplyRotate(i, room);
		GO(cur_cctv + 1, room);
		room.swap(prev_room);
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	vector<vector<char>> room = vector<vector<char>>(n, vector<char>(m, 0));
	cctvs.reserve(8);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int x; cin >> x;
			room[i][j] = x;
			if (0 != x && 6 != x)
			{
				CCTV c;
				c.dirs.reserve(4);
				switch (x)
				{	
				case 1:
					c.dirs.emplace_back(RIGHT);
					break;
				case 2:
					c.dirs.emplace_back(RIGHT);
					c.dirs.emplace_back(LEFT);
					break;
				case 3:
					c.dirs.emplace_back(RIGHT);
					c.dirs.emplace_back(UP);
					break;
				case 4:
					c.dirs.emplace_back(RIGHT);
					c.dirs.emplace_back(LEFT);
					c.dirs.emplace_back(UP);
					break;
				case 5:
					c.dirs.emplace_back(RIGHT);
					c.dirs.emplace_back(LEFT);
					c.dirs.emplace_back(UP);
					c.dirs.emplace_back(DOWN);
					break;
				default:
					break;
				}
				c.ypos = i;
				c.xpos = j;
				cctvs.emplace_back(move(c));
			}
		}
	}
	GO(0, room);
	cout << ans;
}