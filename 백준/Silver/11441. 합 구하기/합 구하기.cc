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
ll arr[100001];
ll acc[100001];
int n;
void Solve()noexcept
{
    cin >> n;
    ll s = 0;
    for (int i = 0; i < n; ++i) 
    {
        cin >> arr[i];
        acc[i] = s + arr[i];
        s += arr[i];
    }
    int t; cin >> t;
    while (t--)
    {
        int a, b; cin >> a >> b;
        a--; b--;
        a--;
        ll aa = 0;
        ll bb = acc[b];
        if (a >= 0)
        {
            aa = acc[a];
        }
        cout << bb - aa << '\n';
    }
}
int main()
{
    FastIO();
    Solve();
}