#include <string>
#include <vector>
#include <map>
#include <unordered_set>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> gems) 
{
    vector<int> answer(2);
    const unordered_set<string> us{gems.begin(),gems.end()};
    map<string,int> m;
    int b = 0;
    int e = 0;
    for(const auto& g:gems)
    {
        ++m[g];
        if(m.size() == us.size())break;
        ++e;
    }
    int d = e - b;
    answer[0]=b + 1;
    answer[1]=e + 1;
    while(e < gems.size())
    {
        const auto& g = gems[b];
         ++b;
        if(0 == --m[g])
        {
            ++e;
            m.erase(g);
            while(e < gems.size())
            {
                ++m[gems[e]];
                if(m.size() == us.size())break;
                ++e;
            }
        }
        if(d > e-b)
        {
            answer[0]=b + 1;
            answer[1]=e + 1;
            d = e-b;
        }
    }
    return answer;
}