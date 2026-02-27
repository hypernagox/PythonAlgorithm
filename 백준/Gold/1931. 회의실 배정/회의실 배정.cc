#include <bits/stdc++.h>
using namespace std;
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
constexpr const int INF = static_cast<int>(1e9);
constexpr const int MIN_INF = -INF;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
pi arr[100001];
void Solve()noexcept
{
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr + n, [](auto a, auto b) {
        if (a.second == b.second)return a.first < b.first;
        return a.second < b.second;
        });
    int ans = 1;
    int cur_last = arr[0].second;
    for (int i = 1; i < n; ++i)
    {
        if (cur_last <= arr[i].first)
        {
            cur_last = arr[i].second;
            ++ans;
        }
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}
