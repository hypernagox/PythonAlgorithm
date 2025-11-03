#include <string>
#include <vector>

using namespace std;
int dp[100001][2];
vector<int> solution(int target) 
{
    vector<int> answer;
    for(int i=1;i<=target;++i)
    {
        if(i <= 20 || i == 50)
        {
            dp[i][0]=dp[i][1]=1;
        }
        else if(i%2 == 0 && i <= 40)
        {
            dp[i][0]=1;
        }
        else if(i%3 == 0 && i<=60)
        {
            dp[i][0]=1;
        }
        else if(i > 50 && i <=70)
        {
            dp[i][0]= 2;
            dp[i][1] = 2;
        }
        else if(i < 70)
        {
            if(i < 40)
            {
                dp[i][0]=2;
                dp[i][1] = 2;
            }
            else
            {
                dp[i][0] = 2;
                dp[i][1] = 1;
            }
        }
        else
        {
            if(dp[i - 60][0] < dp[i - 50][0])
            {
                dp[i][0] = dp[i - 60][0] + 1;
                dp[i][1] = dp[i - 60][1] + 0;
            }
            else if(dp[i - 60][0] > dp[i - 50][0])
            {
                dp[i][0] = dp[i - 50][0] + 1;
                dp[i][1] = dp[i - 50][1] + 1;
            }
            else
            {
                 dp[i][0] = dp[i - 50][0] + 1;
                 dp[i][1]=max(dp[i-60][1],dp[i-50][1] + 1);
            }
        }
    }
    return vector<int>{dp[target][0],dp[target][1]};
}