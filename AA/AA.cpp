#include <iostream>
#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;
int dp[10001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<pair<int, int>> items;
    for (int i = 0; i < n; ++i) {
        int v, c, k; cin >> v >> c >> k;
        for (int j = k; k >= 1; k = k >> 1) {
            j = k - (k >> 1);
            items.emplace_back(v * j, c * j);
        }
    }
    const int num = (int)items.size();
    int res = -1;
    for (int i = 0; i < num; ++i) {
        for (int j = m; j >= items[i].first; --j) {
            dp[j] = max(dp[j], dp[j - items[i].first] + items[i].second);
            res = max(res, dp[j]);
        }
    }
    cout << res;
}