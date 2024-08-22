#include <iostream>
#include <algorithm>
#include <ranges>
#include <vector>
#include <numeric>
using namespace std;
int n, m;
vector<pair<int, int>> c;
vector<pair<int, int>> h;
vector<vector<int>> result;
int csize;
void combinationUtil(int start, vector<int>& current) {
	
	if (current.size() == m) {
		result.emplace_back(current);
		return;
	}
	for (int i = start; i < csize; ++i) {
		current.push_back(i);
		combinationUtil(i + 1, current);
		current.pop_back(); 
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	c.reserve(13);
	h.reserve(50);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int x; cin >> x;
			if (2 == x) {
				c.emplace_back(i, j);
				++csize;
			}
			else if (1 == x) {
				h.emplace_back(i, j);
			}
		}
	}
	vector<int> current;
	current.reserve(1000000);
	result.reserve(1000000);
	combinationUtil(0, current);
	int sum = 987654321;
	for (const auto& c_home : result) {
		int temp = 0;
		for (const auto homes : h) {
			int minval = 987654321;
			for (const auto i : c_home) {
				minval = min(minval, abs(homes.first - c[i].first) + abs(homes.second - c[i].second));
			}
			temp += minval;
		}
		sum = min(sum, temp);
	}
	cout << sum;
}