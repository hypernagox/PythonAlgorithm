#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

vector<int> solution(vector<string> gems) 
{
    const set<string> s{gems.begin(),gems.end()};
    int b = 0;
    int e = 0;
    map<string,int> m;
    for(const auto& g:gems)
    {
        ++m[g];
        if(m.size() == s.size())break;
        ++e;
    }
   // --e;
    int d = e-b;
    vector<int> answer(2);
    answer[0]=b+1;
    answer[1]=e+1;
    while(e < gems.size())
    {
        if(0 == --m[gems[b]])
        {
            ++e;
            m.erase(gems[b]);
            while(e < gems.size() && m.size() != s.size())
            {
                ++m[gems[e]];
                if(m.size() == s.size())break;
                ++e;
            }
        }
        ++b;
        if(d > e - b)
        {
            d=e-b;
            answer[0]=b+1;
            answer[1]=e+1;
        }
    }
    return answer;
}