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
int Check(const vector<int>& v, const int mid)
{
    int s = 0;
    for (const auto i : v)
    {
        s += (i - 1) / mid;
    }
    return s;
}
void Solve() noexcept
{
    int n, m, l; cin >> n >> m >> l;
    vector<int> v;
    v.emplace_back(0);
    v.emplace_back(l);
    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        v.emplace_back(x);
    }
    sort(v.begin(), v.end());
    vector<int> v2;
    int right = 0;
    for (int i = 1; i < v.size(); ++i)
    {
        const auto d = v[i] - v[i - 1];
        v2.emplace_back(d);
        right = max(right, d);
    }
    int left = 1;
    right++;
    int ans = right;
    while (left < right)
    {
        const auto mid = (left + right) / 2;
        const auto val = Check(v2, mid);
        if (val > m)
        {
            left = mid + 1;
        }
        else 
        {
            ans = mid;
            right = mid;
        }
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}