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
void Num1(vector<int>& stack)
{
    int x; cin >> x;
    stack.emplace_back(x);
}
void Num2(vector<int>& stack)
{
    if (stack.empty())
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << stack.back() << '\n';
        stack.pop_back();
    }
}
void Num3(vector<int>& stack)
{
    cout << stack.size() << '\n';
}
void Num4(vector<int>& stack)
{
    cout << stack.empty() << '\n';
}
void Num5(vector<int>& stack)
{
    if (stack.empty())
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << stack.back() << '\n';
    }
}
void Solve()noexcept
{
    vector<int> stack;
    int t; cin >> t; stack.reserve(t);
    constexpr const decltype(&Num1) fps[]
    {
        Num1,
        Num2,
        Num3,
        Num4,
        Num5,
    };
    while (t--)
    {
        int c; cin >> c;
        fps[c - 1](stack);
    }
}
int main()
{
    FastIO();
    Solve();
}