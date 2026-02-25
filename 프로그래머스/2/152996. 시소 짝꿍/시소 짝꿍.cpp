#include <bits/stdc++.h>
using namespace std;
// 42 -> x * 2
// 43 -> x / 3 * 4
// 32 -> x / 2 * 3
constexpr const pair<int,int> mul[]
{
    {1,1},
    {1,2},
    {3,4},
    {2,3},
};
long long solution(vector<int> weights)
{
    long long answer = 0;
    sort(weights.begin(),weights.end());
    for(int i=0;i<weights.size() - 1;++i)
    {
        for(const auto [div, m] : mul)
        {
            if (weights[i] % div != 0) continue;
            const auto target = weights[i] / div * m;
            const auto [lb, up] = equal_range(weights.begin() + i + 1,weights.end(),target);
            answer += (up - lb);
        }
    }
    return answer;
}