#include <iostream>
#include <algorithm>
#include <ranges>
#include <vector>
#include <numeric>
using namespace std;
constexpr int dy[4]{ -1,0,1,0 };
constexpr int dx[4]{ 0,1,0,-1 };
int n, m;
vector<pair<int, int>> c;
vector<pair<int, int>> h;
vector<int> cost[100];
vector<std::vector<int>> result; 
void combinationUtil(int m, int start, std::vector<int>& current) {
	
	if (current.size() == m) {
		result.push_back(current);
		return;
	}
	for (int i = start; i < c.size(); ++i) {
		current.push_back(i);
		combinationUtil(m, i + 1, current);
		current.pop_back(); 
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int x; cin >> x;
			if (2 == x) {
				c.emplace_back(i, j);
			}
			else if (1 == x) {
				h.emplace_back(i, j);
			}
		}
	}
	for (int cnt = 0; auto h_:h) {
		for (auto c_ : c) {
			cost[cnt].emplace_back(abs(h_.first - c_.first) + abs(h_.second - c_.second));
		}
		++cnt;
	}
	vector<int> current;
	for (int i = 1; i <= m; ++i) {
		combinationUtil(i, 0, current);
	}
	int sum = 987654321;
	for (int i = 0; i < result.size(); ++i) {
		int res = 0;
		for (int j = 0; j < h.size(); ++j) {
			int minval = 987654321;
			for (auto k : result[i]) {
				minval = min(minval, cost[j][k]);
			}
			res += minval;
		}
		sum = min(sum, res);
	}
	cout << sum;
}