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
    ll l, range, power, bomb;
    cin >> l >> range >> power >> bomb;

    vector<ll> zombies;
    zombies.reserve(l);
    for (int i = 0; i < l; ++i)
    {
        ll x; cin >> x;
        zombies.emplace_back(x);
    }

    
    ll active_bombs = 0;

   
    vector<bool> used_bomb(l, false);

    for (ll i = 0; i < l; ++i)
    {
        
        if (i >= range && used_bomb[i - range]) {
            active_bombs--;
        }

        const auto dist = i + 1LL;
        const auto hp = zombies[i];

        if (hp == 0) continue;

       
        const auto dmg = (min(dist, range) - active_bombs) * power;

        if (dmg < hp)
        {
            if (bomb > 0)
            {
                used_bomb[i] = true;
                active_bombs++;    
                --bomb;          
            }
            else
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}
int main()
{
    FastIO();
    Solve();
}