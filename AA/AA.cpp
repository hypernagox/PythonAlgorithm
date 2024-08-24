#include <iostream>
#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;
struct Point {
	int num;
	int x, y, z;
	uint64_t getCost(const Point& p)const {
		return min({ abs(x - p.x),abs(y - p.y),abs(z - p.z) });
	}
};
struct Line {
	uint64_t cost;
	int a, b;
	auto operator<=>(const Line&)const = default;
};
struct UnionFind {
	UnionFind(int n) :rank(n), parents(n) { for (int i = 0; i < n; ++i)parents[i] = i; }
	int Find(int u) {return parents[u] = parents[u] == u ? u : Find(parents[u]);}
	bool Union(int u, int v) {
		u = Find(u);
		v = Find(v);
		if (u == v)return false;
		if (rank[u] > rank[v])swap(u, v);
		parents[v] = u;
		if (rank[u] == rank[v])++rank[v];
		return true;
	}
	vector<int> parents;
	vector<int> rank;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<Point> v[3];
	vector<Line> l;
	l.reserve(3 * n);
	UnionFind uf(n);
	for (auto& v_ : v)v_.reserve(n);
	for (int i = 0; i < n;++i) {
		Point p;
		p.num = i;
		cin >> p.x >> p.y >> p.z;
		for (auto& v_ : v)v_.emplace_back(p);
	}
	ranges::sort(v[0], {}, &Point::x);
	ranges::sort(v[1], {}, &Point::y);
	ranges::sort(v[2], {}, &Point::z);
	for (auto& v_ : v) {
		for (int i = 1; i < n; ++i) {
			l.emplace_back(v_[i - 1].getCost(v_[i]), v_[i - 1].num, v_[i].num);
		}
	}
	ranges::sort(l);
	int cnt = 0;
	uint64_t cost = 0;
	for (const auto& line : l) {
		if (uf.Union(line.a, line.b)) {
			++cnt;
			cost += line.cost;
		}
		if (cnt == n)break;
	}
	cout << cost;
}