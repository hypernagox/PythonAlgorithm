#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[2][1000001];
int solution(vector<int> money) 
{
    int answer = 0;
    // dp[털어/안털어][k] -> k번째 집을 털어/안털어의 최대값
    // dp[털어][k] = max(dp[안털어][k-1] + table[k] , dp[털어][k-1]);
    // dp[안털어][k] = max(dp[털어][k-1],dp[안털어][k-1]);
    // 문제는 첫번째 집임
    
    // 0번집 무조건 털어
    //dp[0][0]=money[0];
    dp[1][0]=money[0];
    dp[0][1]=money[0];
    for(int i=1;i<money.size() - 1;++i)
    {
        // 안털어
        dp[0][i] = max(dp[0][i-1],dp[1][i-1]);
        // 털어
        dp[1][i] = dp[0][i-1] + money[i];
        answer=max({answer,dp[0][i+0],dp[1][i+0]});
    }
    memset(dp,0,sizeof(dp));
    dp[0][0]=0;
    dp[1][0]=0;
    dp[1][1]=money[1];
   // dp[0][1]=money[1];
    for(int i=2;i<money.size();++i)
    {
        // 안털어
        dp[0][i] = max(dp[0][i-1],dp[1][i-1]);
        // 털어
        dp[1][i] = dp[0][i-1] + money[i];
         answer=max({answer,dp[0][i+0],dp[1][i+0]});
    }
     //answer = max({answer,dp[1][money.size()-1]});
    return answer - 0;
}