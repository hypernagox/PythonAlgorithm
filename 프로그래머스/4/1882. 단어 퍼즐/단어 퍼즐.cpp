#include <bits/stdc++.h>
using namespace std;
int dp[20001];
constexpr const int INF = 987654321;
int solution(vector<string> strs, string t)
{
    fill(dp,dp+20001,INF);
    const auto N = (int)t.size();
    dp[0]=0;
    for(int i=0;i<N;++i)
    {
        if(dp[i]==INF)continue;
        // i - 1까진 만들어져있으니 i 부터 시작해서 조각을 붙여서 결과가 i + len 길이 일 때 값을 구해보자
        for(const auto& str: strs)
        {
            // i - 1 까진 만들어져있다고 가정하고 거기에 이어붙이기
            bool flag = true;
            const auto len = (int)str.size();
            if(i + len > N)continue;
            for(int k=0;k<len;++k)
            {
                if(t[i+k] != str[k])
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                dp[i+len]=min(dp[i+len],dp[i]+1); // i - 1까진 만들어져있고 거기에 이어붙임
            }
        }
    }
    return INF == dp[N] ? -1:dp[N];
}