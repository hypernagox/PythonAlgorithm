#include <bits/stdc++.h>
using namespace std;
int solution(int n, vector<int> stations, int w)
{
    const auto rad = (2 * w) + 1;
    sort(stations.begin(),stations.end());
    int start = 1; // 전파가 도달하지 않는 것으로 알고있는 시작점
    int ans = 0;
    for(const auto s : stations)
    {
        const auto left = s - w;
        const auto right = s + w;
        // 전파가 도달하는 가장 가까운곳이 내가 아는곳 보다 멀리있다 빈 구간이 있다.
        if(start < left)
        {
            ans += ((left - start) + (rad - 1)) / rad;
        }
        start = right + 1;
    }
    if(start < n + 1)
    {
         ans += ((n + 1 - start) + (rad - 1)) / rad;
    }
    return ans;
}