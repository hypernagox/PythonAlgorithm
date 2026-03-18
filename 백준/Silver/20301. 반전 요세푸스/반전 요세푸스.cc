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
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    int dir = 1;
    int cur_pos = 0;
    int removed = 0;
    while (!v.empty())
    {
        int sz = static_cast<int>(v.size());
        int target;

        if (dir == 1)
        {
            target = (cur_pos + k - 1) % sz;
        }
        else
        {
            target = (cur_pos - (k - 1)) % sz;
            if (target < 0)
            {
                target += sz;
            }
        }

        cout << v[target] << '\n';
        v.erase(v.begin() + target);
        ++removed;

        if (v.empty())
        {
            break;
        }

        int new_sz = static_cast<int>(v.size());

        int next_same;
        int next_flip;

        if (dir == 1)
        {
            next_same = target % new_sz;                 
            next_flip = (target - 1 + new_sz) % new_sz;    
        }
        else
        {
            next_same = (target - 1 + new_sz) % new_sz;   
            next_flip = target % new_sz;                
        }
        if (removed % m == 0)
        {
            dir = -dir;
            cur_pos = next_flip;
        }
        else
        {
            cur_pos = next_same;
        }
    }
}
int main()
{
    FastIO();
    Solve();
}