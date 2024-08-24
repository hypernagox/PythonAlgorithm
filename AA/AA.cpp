#include <iostream>
#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;
struct Point {
    int x, y;
};
struct Line {
    Point A, B;
    int crossProduct(const Point& C) const {
        return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
    }
    bool onSegment(const Point& C) const {
        return C.x >= std::min(A.x, B.x) && C.x <= std::max(A.x, B.x) &&
            C.y >= std::min(A.y, B.y) && C.y <= std::max(A.y, B.y);
    }
};
bool doIntersect(const Line& L1, const Line& L2) {
    const int d1 = L1.crossProduct(L2.A);
    const int d2 = L1.crossProduct(L2.B);
    const int d3 = L2.crossProduct(L1.A);
    const int d4 = L2.crossProduct(L1.B);
    return (d1 * d2 < 0 && d3 * d4 < 0) ||
        (d1 == 0 && L1.onSegment(L2.A)) ||
        (d2 == 0 && L1.onSegment(L2.B)) ||
        (d3 == 0 && L2.onSegment(L1.A)) ||
        (d4 == 0 && L2.onSegment(L1.B));
}
class UnionFind {
public:
    UnionFind(int n) :rank(n), parents(n), num(n,1) { for (int i = 0; i < n; ++i)parents[i] = i; }
    int Find(int u) {
        return parents[u] = parents[u] == u ? u : Find(parents[u]);
    }
    void Union(int u, int v) {
        u = Find(u);
        v = Find(v);
        if (u == v) return;
        if (rank[u] > rank[v]) {
            parents[v] = u;
            num[u] += num[v];
        }
        else {
            parents[u] = v;
            num[v] += num[u];
            if (rank[u] == rank[v]) ++rank[v];
        }
    }
public:
    vector<int> parents;
    vector<int> rank;
    vector<int> num;
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<Line> v;
    v.reserve(n);
    UnionFind uf(n);
    for (int i = 0; i < n; ++i) {
        short a, b, c, d;
        cin >> a >> b >> c >> d;
        v.emplace_back(Point{ a,b }, Point{ c,d });
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (doIntersect(v[i], v[j])) {
                uf.Union(i, j);
            }
        }
    }
    int g = 0;
    int m = -1;
    for (int i = 0; i < n; ++i) {
        if (uf.parents[i] == i) {
            ++g;
            m = max(m, uf.num[i]);
        }
    }
    cout << g << '\n' << m;
}