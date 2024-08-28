#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
struct Item { int v, m; };
Item item[300000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	uint64_t res = 0;
	multiset<int> ms;
	for (int i = 0; i < n; ++i)cin >> item[i].m >> item[i].v;
	for (int i = 0; i < k; ++i) { int w; cin >> w; ms.emplace(w); }
	ranges::sort(item, item + n, greater{}, &Item::v);
	int cnt = k;
	for (int i = 0; cnt && i < n; ++i) {
		const auto iter = ms.lower_bound(item[i].m);
		if (ms.end() != iter) {
			ms.erase(iter);
			res += item[i].v;
			--cnt;
		}
	}
	cout << res;
}