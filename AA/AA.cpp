#include <iostream>
#include <algorithm>
using namespace std;
struct Line {
	uint16_t l, r;
	uint16_t v;
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	Line l[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)cin >> l[i].l >> l[i].r;
	ranges::sort(l, l + n, {}, &Line::l);
	int res = 1;
	l[0].v = 1;
	for (int i = 1; i < n; ++i) {
		int max_val = 1;
		for (int j = i - 1; j >= 0; --j) {
			if (l[j].r < l[i].r && l[j].v  + 1> max_val) {
				max_val = l[j].v + 1;
			}
		}
		l[i].v = max_val;
		res = max(res, max_val);
	}
	cout << n - res;
}
