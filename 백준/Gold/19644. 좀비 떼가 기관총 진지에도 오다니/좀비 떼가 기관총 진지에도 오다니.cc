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
    ll l, range, power, bomb; cin >> l >> range >> power >> bomb;
    vector<ll> zombies; zombies.reserve(l);
    for (int i = 0; i < l; ++i)
    {
        ll x; cin >> x;
        zombies.emplace_back(x);
    }
    vector<ll> diff(l + 1, 0);
    ll cur = 1;

    for (ll i = 0; i < l; ++i)
    {
        cur += diff[i];
        const auto hp = zombies[i];
        const auto dmg = cur * power;
        if (dmg < hp)
        {
            if (bomb)
            {
                --bomb;
            }
            else
            {
                cout << "NO";
                return;
            }
        }
        else
        {
            ++cur;
            if (i + range < l)
            {
                --diff[i + range];
            }
        }
    }
    cout << "YES";
}
int main()
{
    FastIO();
    Solve();
}