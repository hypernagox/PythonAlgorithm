#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
int arr[1000001];
int freq[1000001];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)cin >> arr[i];
    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        const auto out_idx = i - m - 1;
        if (out_idx >= 0)
        {
            --freq[arr[out_idx]];
        }
        ans += freq[arr[i] ^ k];
        ++freq[arr[i]];
    }
    cout << ans;
}