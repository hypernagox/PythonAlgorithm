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
int arr[100001];
map<int, int> mm;
bool DecAndErase(const auto target)
{
    if (mm.end() == target)return false;
    if (--target->second == 0)
    {
        mm.erase(target);
    }
    return true;
}
void Solve() noexcept
{
    int n, m; cin >> n >> m;
   
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        ++mm[arr[i]];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (!DecAndErase(mm.find(arr[i])))continue;
        const auto iter = mm.lower_bound(m - arr[i]);
        if (mm.end() != iter)
        {
            ++ans;
            DecAndErase(iter);
        }
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}