#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int solution(vector<int> queue1, vector<int> queue2)
{
    ll val1 = accumulate(queue1.begin(), queue1.end(), 0LL);
    ll val2 = accumulate(queue2.begin(), queue2.end(), 0LL);
    ll target = val1 + val2;
    if (target & 1)return-1;
    target /= 2;
    ll cursor1 = 0;
    ll cursor2 = 0;
    ll cnt = 0;
    const auto prev = queue1.size();
    for (;;)
    {
        if (val1 == val2)return cnt;
        if (cnt >= 300000)return -1;
        if (queue1.size() <= cursor1 || queue2.size() <= cursor2)return -1;
        if (val1 < val2)
        {
            // 2가 더 커서
            // 2에서 꺼내서 준다
            val1 += queue2[cursor2];
            val2 -= queue2[cursor2];
            queue1.emplace_back(queue2[cursor2]);
            ++cursor2;
        }
        else
        {
            // 1가 더 커서
            // 1에서 꺼내서 준다
            val2 += queue1[cursor1];
            val1 -= queue1[cursor1];
            queue2.emplace_back(queue1[cursor1]);
            ++cursor1;
        }
        ++cnt;
    }
    return -1;
}