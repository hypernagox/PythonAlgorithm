#include <bits/stdc++.h>
using namespace std;
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
constexpr const int INF = 987654321;
constexpr const int MIN_INF = -INF;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
void Solve()noexcept
{
    int len, height, width;

    cin >> len >> height >> width;

    cout << (int)(len / sqrt(height * height + width * width) * height) << " " << (int)(len / sqrt(height * height + width * width) * width) << "\n";
}
int main()
{
    FastIO();
    Solve();
}
