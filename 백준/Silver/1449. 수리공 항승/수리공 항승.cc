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
void Solve() noexcept
{
    int n, l; cin >> n >> l;
    vector<int> pos; pos.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        pos.emplace_back(x);
    }
    sort(pos.begin(), pos.end());
    int cnt = 1;
    int cur_last = pos[0];
    for (int i = 1; i < n; ++i)
    {
        const auto delta = pos[i] - cur_last + 1;
        if (delta > l)
        {
            cur_last = pos[i];
            ++cnt;
        }
    }
    cout << cnt;
}
int main()
{
    FastIO();
    Solve();
}