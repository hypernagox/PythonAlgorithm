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
    int n; cin >> n;
    vector<int> v; v.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        v.emplace_back(x);
    }
    sort(v.begin(), v.end());
    int cur = 0;
    for (int i = 0; i < n; ++i)
    {
        if (v[i] <= cur + 1)
        {
            cur += v[i];
        }
        else
        {
            break;
        }
    }
    cout << cur + 1;
}
int main()
{
    FastIO();
    Solve();
}