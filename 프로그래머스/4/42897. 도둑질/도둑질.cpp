#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[2][1000001];
int solution(vector<int> money) 
{
    int answer = 0;
    // 첫집털어
    dp[0][1]=0;
    dp[1][1]=money[0];
    dp[0][2]=money[0];
    dp[1][2]=money[0];
    for(int i=2;i<money.size() - 1;++i)
    {
        // 안털어
        dp[0][i + 1]=max(dp[1][i],dp[0][i]);
        // 털어
        dp[1][i+1]=dp[0][i]+money[i];
        answer=max({answer,dp[0][i+1],dp[1][i+1]});
    }
    // 첫집 안털어
    memset(dp,0,sizeof(dp));
    dp[0][1]=0;
    dp[1][1]=0;
    dp[0][2]=0;
    dp[1][2]=money[1];
    for(int i=1;i<money.size();++i)
    {
        // 안털어
        dp[0][i + 1]=max(dp[1][i],dp[0][i]);
        // 털어
        dp[1][i+1]=dp[0][i]+money[i];
        answer=max({answer,dp[0][i+1],dp[1][i+1]});
    }
    return answer;
}