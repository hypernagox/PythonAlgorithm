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
int arr[101];
int n;
void Solve() noexcept
{
    int n; cin >> n;
    for (int i = 0; i < n; ++i)cin >> arr[i];
    int s = 0;
    for (int i = n - 2; i >= 0; --i)
    {
        if (arr[i + 1] <= arr[i])
        {
            const auto delta = arr[i] - arr[i + 1];
            s += delta + 1;
            arr[i] -= (delta + 1);
        }
    }
    cout << s;
}
int main()
{
    FastIO();
    Solve();
}