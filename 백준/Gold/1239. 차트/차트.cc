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
    int arr[8]{};
    for (int i = 0; i < n; ++i)cin >> arr[i];
    sort(arr, arr + n);
    int ans = 0;
    do {
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            int s = 0;
            for (int j = i; j < n; ++j)
            {
                s += arr[j];
                if (s >= 50)
                {
                    cnt += s == 50;
                    break;
                }
            }
        }
        ans = max(ans, cnt - 1);    // 절반을 가르는 선 마지막 하나가 중복임 (시작과 끝)
    } while (next_permutation(arr, arr + n));
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}