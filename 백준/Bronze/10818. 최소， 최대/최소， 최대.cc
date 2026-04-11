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
int arr[1000001];
void Solve() noexcept
{
    int n; cin >> n;
    for (int i = 0; i < n; ++i)cin >> arr[i];
    const auto [m, M] = ranges::minmax_element(arr, arr + n);
    cout << *m << ' ' << *M;
}
int main()
{
    FastIO();
    Solve();
}