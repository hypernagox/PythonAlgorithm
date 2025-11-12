#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

vector<int> solution(vector<string> gems) 
{
    vector<int> answer(2,0);
    const auto need = (int)set<string>{gems.begin(),gems.end()}.size();
    map<string,int> m;
    int have = 0;
    int s = 0;
    int len = 987654321;
    for(int i=0;i<gems.size();++i)
    {
        if(1 == ++m[gems[i]])
        {
            ++have;
        }
        while(need == have)
        {
            if(len > i - s)
            {
                len = i-s;
                answer[0]=s+1;
                answer[1]=i+1;
            }
            if(0 == --m[gems[s]])
            {
                --have;
            }
            ++s;
        }
    }
    return answer;
}