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
    vector<int> six, one;
    int n, m; cin >> n >> m;
    six.reserve(m); one.reserve(m);
    for (int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        six.emplace_back(a);
        one.emplace_back(b);
    }
    sort(six.begin(), six.end());
    sort(one.begin(), one.end());
    const auto nat = n % 6;
    const auto pack = n / 6;
    cout << (pack * min(six.front(), one.front() * 6)) + min(nat * one.front(), six.front());
}
int main()
{
    FastIO();
    Solve();
}