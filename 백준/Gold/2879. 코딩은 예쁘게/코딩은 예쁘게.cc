#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
constexpr const int MAX_VAL = 987654321;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;

    vector<int> arr(n), target(n), d(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    for (int i = 0; i < n; ++i) cin >> target[i];

    for (int i = 0; i < n; ++i) d[i] = target[i] - arr[i];

    int ans = abs(d[0]);

    for (int i = 1; i < n; ++i)
    {
        if (d[i] != 0 && d[i - 1] != 0 && ((d[i] > 0) == (d[i - 1] > 0)))
        {
            int cur = abs(d[i]);
            int prev = abs(d[i - 1]);
            if (cur > prev) ans += (cur - prev);
        }
        else
        {
            ans += abs(d[i]);
        }
    }

    cout << ans;
}