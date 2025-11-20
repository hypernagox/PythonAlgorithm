#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;
    int cur_time = 0;
    map<string,int> m;
    for(auto& city:cities)
    {
        for(auto& i : city)i=tolower(i);
        const auto iter = m.find(city);
        if(iter == m.end() || 0 == cacheSize)
        {
            answer += 5;
            if(m.size() == cacheSize)
            {
                string s="";
                int min_t=987654321;
                for(const auto& [c,t]:m)
                {
                    if(min_t > t)
                    {
                        s=c;
                        min_t=t;
                    }
                }
                m.erase(s);
                m.emplace(city,cur_time);
            }
            else
            {
                m.emplace(city,cur_time);
            }
        }
        else
        {
            iter->second=cur_time;
            answer += 1;
        }
        ++cur_time;
    }
    return answer;
}