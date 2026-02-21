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
string arr[51];
void Solve()noexcept
{
    int n; cin >> n;
    int s = 0;
    for (int i = 0; i < n; ++i)
    {
        string temp; cin >> temp;
        for (int j = 0; j < temp.size(); ++j)
        {
            arr[j].push_back(temp[j]);
            s = temp.size();
        }
    }
    string ans;
    for (int i = 0; i < s; ++i)
    {
        const auto ch = arr[i].front();
        if (all_of(arr[i].begin(), arr[i].end(), [ch](auto c) {return c == ch; }))
        {
            ans.push_back(ch);
        }
        else
        {
            ans.push_back('?');
        }
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}