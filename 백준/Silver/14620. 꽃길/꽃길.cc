#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int mat[11][11];
int n;
constexpr const int dy[]{ -1,0,1,0 };
constexpr const int dx[]{ 0,1,0,-1 };
vector<pi> points;
vector<pi> cur_select;
constexpr const int MAX_VAL = 987654321;
int min_val = MAX_VAL;
int Calculate()
{
	int sum = 0;
	set<pi> s;
	for (int i = 0; i < cur_select.size(); ++i)
	{
		const auto [y, x] = cur_select[i];
		if(!s.emplace(y,x).second)return MAX_VAL;
		sum += mat[y][x];
		for (int k = 0; k < 4; ++k)
		{
			const auto ny = y + dy[k];
			const auto nx = x + dx[k];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n)return MAX_VAL;
			if (!s.emplace(ny, nx).second)return MAX_VAL;
			sum += mat[ny][nx];
		}
	}
	return sum;
}
void GO(const int cur = 0)
{
	if (3 == cur_select.size())
	{
		//cout << Calculate() << endl;
		min_val = min(min_val, Calculate());
		return;
	}
	for (int i = cur; i < points.size(); ++i)
	{
		cur_select.emplace_back(points[i]);
		GO(i + 1);
		cur_select.pop_back();
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> mat[i][j];
			points.emplace_back(i, j);
		}
	}
	GO();
	cout << min_val;
}