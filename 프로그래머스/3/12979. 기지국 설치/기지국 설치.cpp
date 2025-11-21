#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    const auto step = (w*2)+1;
    int pos = 1; // 커버를 시작해야함
    for(int i=0;i<stations.size();++i)
    {
        const auto left = stations[i]-w;
        const auto right = stations[i]+w;
        if(pos < left)
        {
            const int gap = left - pos;
            answer += (int)ceil(gap / (float)step); // 빈구간은 이만큼 필요
        }
        pos = right + 1;
    }
    // 커버를 시작해야하는 부분이 n보다 작거나 같다면
    if(pos <= n)
    {
        const auto gap = n - pos + 1;
        answer += (int)ceil(gap / (float)step);
    }
    return answer;
}