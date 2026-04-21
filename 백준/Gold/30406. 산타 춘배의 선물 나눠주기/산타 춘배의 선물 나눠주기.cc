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
int arr[4];
void Solve() noexcept
{
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x;
       
        ++arr[x];
    }
    int ans = 0;
    // 0 3 조합 다 털고
    if (arr[0] < arr[3])
    {
        arr[3] -= arr[0];
        ans += 3 * arr[0];
        arr[0] = 0;
       
    }
    else
    {
        arr[0] -= arr[3];
        ans += 3 * arr[3];
        arr[3] = 0;
    }
    // 12조합다털고
    if (arr[1] < arr[2])
    {
        arr[2] -= arr[1];
        ans += 3 * arr[1];
        arr[1] = 0;

    }
    else
    {
        arr[1] -= arr[2];
        ans += 3 * arr[2];
        arr[2] = 0;
    }
    if (arr[0] > 0)
    {
        if (arr[2] > 0)
        {
            ans += 2 * min(arr[2], arr[0]);
        }
        else if (arr[1] > 0)
        {
            ans += 1 * min(arr[1], arr[0]);
        }
    }
    else
    {
        // 3이 남음
        if (arr[2] > 0)
        {
            ans += 1 * min(arr[2], arr[3]);
        }
        else if (arr[1] > 0)
        {
            ans += 2 * min(arr[1], arr[3]);
        }
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}