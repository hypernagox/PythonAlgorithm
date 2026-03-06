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
ull arr[1000001];
void Solve()noexcept
{
    int n; cin >> n;
    fill(begin(arr), end(arr), 1);
    for (int i = 2; i <= 1000000; ++i)
    {
        arr[i] += arr[i - 1];
        for (int j = i; j <= 1000000; j += i)
        {
            arr[j] += i;
        }
    }
    cout << arr[n];
}
int main()
{
    FastIO();
    Solve();
}