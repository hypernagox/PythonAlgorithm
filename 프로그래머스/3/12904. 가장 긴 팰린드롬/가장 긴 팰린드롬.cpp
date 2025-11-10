#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool dp[2551][2551];
int solution(string s)
{
    int answer=1;
    for(int i=0;i<s.size();++i)dp[i][i]=true;
    for(int i=0;i<s.size() - 1;++i)
    {
        if(s[i]==s[i+1])
        {
            dp[i][i+1]=true;
            answer = 2;
        }
    }
    for(int l=3;l<=s.size();++l)
    {
        for(int start=0;start <= s.size()-l;++start)
        {
            const auto end = start + l - 1;
            if(s[start] == s[end] && dp[start + 1][end - 1])
            {
                dp[start][end]=true;
                answer =max(answer,l);
            }
        }
    }
    return answer;
}