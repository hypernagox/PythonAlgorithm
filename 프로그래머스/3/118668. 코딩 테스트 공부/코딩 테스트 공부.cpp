#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int dp[151][151]; // 현재[알고력][코딩력]일때 최대도달을 위해 필요한 최단시간
int maxAlp;
int maxCop;
int sol(int alp, int cop, const vector<vector<int>>& problems)
{
    alp = min(alp,maxAlp);
    cop = min (cop,maxCop);
    if(alp >= maxAlp && cop >= maxCop)return 0;
    auto& ref = dp[alp][cop];
    if(ref)return ref;
    ref = 987654321;
    if(alp < maxAlp)
    {  // 걍 알고력 올리기
        ref = min(ref, 1 + sol(alp+1,cop,problems));
    }
    if(cop < maxCop)
    {// 걍 코딩력 올리기
        ref = min(ref, 1 + sol(alp,cop + 1,problems));
    }
    // 지금 풀 수 있는거 풀어보기
    for(const auto& p:problems)
    {
        if(alp >= p[0] && cop >= p[1])
        {
            const auto na = alp + p[2];
            const auto nc = cop + p[3];
            ref=min(ref,p[4]+sol(na,nc,problems));
        }
    }
    return ref;
}
int solution(int alp, int cop, vector<vector<int>> problems) 
{
    int answer = 0;
    for(const auto& p :problems)
    {
        maxAlp = max(maxAlp,p[0]);
        maxCop = max(maxCop,p[1]);
    }
    return sol(alp,cop,problems);
}