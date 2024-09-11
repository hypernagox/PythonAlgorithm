#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
#include <cmath>
using namespace std;
using ll = long long;
ll x, y;
struct Point {
	ll x, y;
};
vector<Point> points;
ll ccw(const Point& a,const Point& b, const Point& c) {
	return ((b.x - a.x) * (c.y - b.y)) - ((c.x - b.x) * (b.y - a.y));
}
bool check_overlap(const Point& a, const Point& b, const Point& c, const Point& d) {
	if (min(a.x, b.x) <= max(c.x, d.x) && max(a.x, b.x) >= min(c.x, d.x) &&
		min(a.y, b.y) <= max(c.y, d.y) && max(a.y, b.y) >= min(c.y, d.y)) {
		return true;
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	points.reserve(4);
	for (int i = 0; i < 4; ++i) {
		ll x, y; cin >> x >> y;
		points.emplace_back(x, y);
	}
	const auto ccw1 = ccw(points[0], points[1], points[2]);
	const auto ccw2 = ccw(points[0], points[1], points[3]);
	const auto ccw3 = ccw(points[2], points[3], points[0]);
	const auto ccw4 = ccw(points[2], points[3], points[1]);
	if (ccw1 * ccw2 < 0 && ccw3 * ccw4 < 0) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}