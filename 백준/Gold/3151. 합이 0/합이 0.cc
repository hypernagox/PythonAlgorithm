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
    ll ans = 0;
    for (int i = 0; i < n - 2; ++i)
    {
        int l = i + 1;
        int r = n - 1;
        const int target = -v[i];
        while (l < r)
        {
            const int val = v[l] + v[r];
            if (val < target)
            {
                ++l;
            }
            else if (val > target)
            {
                --r;
            }
            else
            {
                if (v[l] == v[r])
                {
                    ll cnt = r - l + 1;
                    ans += cnt * (cnt - 1) / 2;
                    break;
                }
                ll leftCnt = 1;
                ll rightCnt = 1;
                while (l + 1 < r && v[l] == v[l + 1])
                {
                    ++leftCnt;
                    ++l;
                }
                while (r - 1 > l && v[r] == v[r - 1])
                {
                    ++rightCnt;
                    --r;
                }
                ans += leftCnt * rightCnt;
                ++l;
                --r;
            }
        }
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}