#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct Item { 
	int v, m;
	auto operator<=>(const Item&)const noexcept = default;
};
Item item[300000];
int bag[300000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	uint64_t res = 0;
	for (int i = 0; i < n; ++i)cin >> item[i].m >> item[i].v;
	for (int i = 0; i < k; ++i) cin >> bag[i];
	ranges::sort(item, item + n, {}, &Item::m);
	ranges::sort(bag, bag + k);
	priority_queue<Item> pq;
	int idx = 0;
	for (int i = 0; i < k; ++i) {
		while (idx <= n && item[idx].m <= bag[i]) {
			pq.emplace(item[idx++]);
		}
		if (!pq.empty()) {
			res += pq.top().v;
			pq.pop();
		}
	}
	cout << res;
}