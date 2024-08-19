#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

class UnionFind
{
public:
	vector<int> parents;
	vector<int> rank;
	
	UnionFind(int n) :rank(n),parents(n) { for (int i = 0; i < n; ++i)parents[i] = i; }

	void Union(int u,int v){
		int uf = Find(u);
		int vf = Find(v);
		if (u == v || uf == vf)return;
		if (rank[uf] > rank[vf])
			swap(uf, vf);
		parents[vf] = uf;
		if (rank[uf] == rank[vf])
			++rank[vf];
	}
	int Find(int u){
		return parents[u] = parents[u] == u ? u : Find(parents[u]);
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> party[50];
	unordered_set<int> tp;
	tp.reserve(50);
	UnionFind uf{ n };
	while (k--) {
		int x; cin >> x;
		tp.emplace(x - 1);
		uf.rank[x - 1] = -50;
	}
	for (int i = 0; i < m; ++i) {
		int x; cin >> x;
		for (int j = 0; j < x; ++j) {
			int y; cin >> y;
			party[i].emplace_back(y);
		}
		int parent = party[i][0] - 1;
		for (int k = 1; k < x; ++k) {
			uf.Union(parent, party[i][k] - 1);
		}
	}
	int res = 0;
	for (int i = 0; i < m; ++i) {
		bool flag = true;
		for (const auto p : party[i]) {
			if (tp.contains(uf.Find(p - 1))) {
				flag = false;
				break;
			}
		}
		if (flag)++res;
	}
	cout << res;
}
