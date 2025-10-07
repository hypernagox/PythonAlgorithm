#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int solution(vector<vector<int>> targets)
{
    int answer = 1; // 하나라도 있기때문에 최소 하나라도 써야함
    vector<pi> sorted;
    for(const auto&v:targets)
    {
        sorted.emplace_back(v[1], v[0]);
    }
    sort(sorted.begin(), sorted.end()); // 끝점이 제일 앞인 녀석 순으로 정렬
    int cur_idx = 0;  // 내가 알고 있는 가장 끝점이 앞인 녀석
    for (int i = 1; i < sorted.size(); ++i)
    {
        if (sorted[cur_idx].first <= sorted[i].second)
        {
            // 내가 아는 가장 끝 점이 앞에오는 녀석과 지금 녀석이 겹치지 않는다.
            // 미사일을 하나 더 써야하고 끝점을 이녀석으로 갱신한다.
            ++answer;
            cur_idx = i;
        }
    }
    return answer;
}