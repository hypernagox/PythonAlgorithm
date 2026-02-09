#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
vector<int> alpha[26];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s, t; cin >> s >> t;
    for (int i = 0; i < t.size(); ++i)
    {
        alpha[t[i] - 'a'].emplace_back(i);
    }
    int cur_idx = -1;
    int res = 1;
    for (int i = 0; i < s.size(); ++i)
    {
        const auto cur_alpha = s[i] - 'a';
        const auto& v = alpha[cur_alpha];
        if (v.empty())
        {
            cout << -1;
            return 0;
        }
        const auto it = upper_bound(v.begin(), v.end(), cur_idx);
        // 지금 찾아야 할 단어 중 인덱스가 나보다 큰 걸 못찾으면
        if (v.end() == it)
        {
            ++res;
            --i;
            cur_idx = -1;
        }
        else
        {
            cur_idx = *it;
        }
    }
    cout << res;
}