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
void Solve()noexcept
{
    ull n;
    cin >> n;
    if (n == 1 || n == 3)
    {
        cout << "SK\n";
    }
    else if (n == 2)
    {
        cout << "CY\n";
    }
    else
    {
        if ((n - 3) % 5 == 1 || (n - 3) % 5 == 3 || (n - 3) % 5 == 0)
        {
            cout << "SK\n";
        }
        else
        {
            cout << "CY\n";
        }
    }
}
int main()
{
    FastIO();
    Solve();
}