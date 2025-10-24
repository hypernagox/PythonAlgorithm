#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int solution(vector<int> a)
{
    int answer = 0;
    set<int> end{ a.begin(),a.end() };
    set<int> begin;
    for (const auto i : a)
    {
        int cnt = 0;
        end.erase(i);
        const auto end_max = end.begin();
        const auto begin_max = begin.begin();
        if (end_max != end.end())
        {
            cnt += (i > *end_max);
        }
        if (begin_max != begin.end())
        {
            cnt += (i > *begin_max);
        }
        if (cnt < 2)
        {
            ++answer;
           // cout << i << endl;
        }
        begin.emplace(i);
    }
    return answer;
}