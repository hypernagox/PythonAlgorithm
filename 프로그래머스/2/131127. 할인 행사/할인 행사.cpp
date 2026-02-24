#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) 
{
    map<string,int> wants;
    for(int i=0;i<want.size();++i)
    {
        wants[want[i]] = number[i];
    }
    map<string,int> cur;
    int ans = 0;
    for(int i=0;i<discount.size();++i)
    {
        int clear_size = (int)wants.size();
        const auto last = min((int)discount.size(),i + 10);
        for(int d = i; d < last;++d)
        {
            const auto& name = discount[d];
            const auto iter = wants.find(name);
            if(wants.end()==iter)continue;
            if(++cur[name] == wants[name])
            {
                --clear_size;
            }
        }
        if(0 == clear_size)
        {
            ++ans;
        }
         cur.clear();
    }
    return ans;
}