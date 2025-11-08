#include <string>
#include <vector>

using namespace std;

int solution(vector<int> cookie) 
{
    int answer = 0;
    for(int i=0;i<cookie.size() - 1;++i)
    {
        int ai=i;
        int bi=i+1;
        int as = cookie[ai];
        int bs =cookie[bi];
        for(;;)
        {
        if(as == bs)
        {
            answer =max(answer,as);
           // break;
        }
        if(ai > 0 && as <= bs)
        {
            --ai;
            as+=cookie[ai];
        }
        else if(bi < cookie.size() - 1 && as >= bs)
        {
            ++bi;
            bs += cookie[bi];
        }
        else break;
        }
    }
    return answer;
}