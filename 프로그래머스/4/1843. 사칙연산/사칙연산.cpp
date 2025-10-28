#include <vector>
#include <string>
#include <iostream>
using namespace std;
vector<char> ops;
vector<int> nums;
vector<vector<int>> dp_max;
vector<vector<int>> dp_min;
int solution(vector<string> arr)
{
    int answer = -1;
    for(const auto& s: arr)
    {
        if(isdigit(s[0]))
        {
            nums.emplace_back(stoi(s));
        }
        else
        {
            ops.emplace_back(s[0]);
        }
    }
    const auto len = (int)nums.size();
    dp_min = vector<vector<int>>(len,vector<int>(len,1<<20));
    dp_max = vector<vector<int>>(len,vector<int>(len,-(1<<20)));
    for(int i=0;i<len;++i)
    {
        // i부터 i까지 부분 합의 최대 최소
        dp_min[i][i]=dp_max[i][i]=nums[i];
    }
    // 길이 2~len
    for(int l = 2; l<=len;++l)
    {
        // 시작
        for(int s = 0;s<=len-l;++s)
        {
            const int e = s + l -1; // 끝
            for(int k=s;k<e;++k) // 경유점
            {
                const auto op =ops[k];
                if(op == '+')
                {
                    dp_max[s][e]=max(dp_max[s][e],dp_max[s][k]+dp_max[k + 1][e]);
                    dp_min[s][e]=min(dp_min[s][e],dp_min[s][k]+dp_min[k + 1][e]);
                }
                else
                {
                     dp_max[s][e]=max(dp_max[s][e],dp_max[s][k] - dp_min[k + 1][e]);
                     dp_min[s][e]=min(dp_min[s][e],dp_min[s][k] - dp_max[k + 1][e]);
                }
            }
        }
    }
    return dp_max[0][len-1];
}