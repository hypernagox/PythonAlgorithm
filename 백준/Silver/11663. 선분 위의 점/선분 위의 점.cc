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
pi lines[100001];
int n, m;
void Solve() noexcept
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)cin >> arr[i];
    for (int i = 0; i < m; ++i)cin >> lines[i].first >> lines[i].second;
    sort(arr, arr + n);
    for (int i = 0; i < m; ++i)
    {
        const auto [s, e] = lines[i];
        const auto iter1 = lower_bound(arr, arr + n, s);
        const auto iter2 = upper_bound(arr, arr + n, e);
        cout << iter2 - iter1 << '\n';
    }
}
int main()
{
    FastIO();
    Solve();
}