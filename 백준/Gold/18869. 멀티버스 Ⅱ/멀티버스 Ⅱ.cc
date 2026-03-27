#include <bits/stdc++.h>
using namespace std;
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
constexpr const int INF = static_cast<int>(1e9) + 1;
constexpr const int MIN_INF = -INF;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
vector<int> arr[101];
void Solve() noexcept
{
    int m, n; cin >> m >> n;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int x; cin >> x;
            arr[i].emplace_back(x);
        }
        auto temp = arr[i];
        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());
        for (int j = 0; j < n; ++j)
        {
            arr[i][j] = lower_bound(temp.begin(), temp.end(), arr[i][j]) - temp.begin();
        }
    }
    int res = 0;
    for (int i = 0; i < m; ++i)
    {
        const auto& v1 = arr[i];
        for (int j = i + 1; j < m; ++j)
        {
            const auto& v2 = arr[j];
            res += (v1 == v2);
        }
    }
    cout << res;
}
int main()
{
    FastIO();
    Solve();
}