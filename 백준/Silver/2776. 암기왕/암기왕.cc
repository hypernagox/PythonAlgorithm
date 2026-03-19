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
    int t; cin >> t;
    vector<int> us; us.reserve(1000001);
    while (t--)
    {
        int n; cin >> n;
        while (n--)
        {
            int x; cin >> x; us.emplace_back(x);
        }
        ranges::sort(us);
        cin >> n;
        while (n--)
        {
            int x; cin >> x;
            cout << ranges::binary_search(us,x) << '\n';
        }
        us.clear();
    }
}
int main()
{
    FastIO();
    Solve();
}