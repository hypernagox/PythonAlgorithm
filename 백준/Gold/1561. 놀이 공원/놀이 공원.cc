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
ll n, m;
ll arr[10001];
ll Cal(const ll t)
{
    ll s = 0;
    for (int i = 0; i < m; ++i)
    {
        s += (t / arr[i]) + 1LL;
    }
    return s;
}
void Solve() noexcept
{
    cin >> n >> m;
    if (n <= m)
    {
        cout << n;
        return;
    }
    for (int i = 0; i < m; ++i)cin >> arr[i];
    ll low = 0;
    ll high = INT32_MAX * 31LL;
    ll ans = 0;
    while (low < high)
    {
        const auto mid = low + (high - low) / 2LL;
        const auto val = Cal(mid);
        if (n <= val)
        {
            // n을 아득히 넘어가더라도 그럼 그냥 n만큼 태우면 그만, 
            // 그래도 시간이 mid는걸린다는 사실엔 변함이없음
            ans = mid;
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    const auto before = Cal(ans - 1); // 직전에 몇명태울수있었지?
    auto diff_num = n - before;
    for (int i = 0; i < m; ++i)
    {
        if (ans % arr[i] != 0)continue; // 정확히 ans초에 끝나기 때문에 배수관계만 가능
        --diff_num;
        if (diff_num == 0)
        {
            cout << i + 1;
            return;
        }
    }
}
int main()
{
    FastIO();
    Solve();
}