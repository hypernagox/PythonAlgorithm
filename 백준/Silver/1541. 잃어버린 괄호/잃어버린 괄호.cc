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
    string str; cin >> str;
    stringstream sstream{ str };
    int n = 0; char c = 0;
    bool turn = 1;
    int res = 0;
    bool flag = false;
    for (;;)
    {
        if (turn)
        {
            if (!(sstream >> n))
            {
                break;
            }
            if (flag)res -= n;
            else res += n;
        }
        else
        {
            if (!(sstream >> c))
            {
                break;
            }
            if (c == '-')flag = true;
        }
        turn = !turn;
    }
    cout << res;
}
int main()
{
    FastIO();
    Solve();
}