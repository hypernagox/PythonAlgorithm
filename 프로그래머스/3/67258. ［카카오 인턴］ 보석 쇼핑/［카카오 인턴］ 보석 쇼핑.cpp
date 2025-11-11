#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

vector<int> solution(vector<string> gems)
{
    vector<int> answer(2,0);
    const set<string> all_gems{gems.begin(),gems.end()};
    map<string,int> m;
    int b = 0;
    int e = 0;
    // 일단 b를 무조건 시작점으로 했을 때 만족하는 구간은?
    for(const auto& g: gems)
    {
        m[g]++;
        if(m.size() == all_gems.size())break;
        ++e;
    }
    int d = e - b;
    answer[0]=b+1;
    answer[1]=e+1;
    // 일단 조건을 만족하는 상태에서 앞을 하나씩 밀어본다.
    while(e < gems.size())
    {
        const auto& key = gems[b];
        ++b;
        // 앞을 밀었더니 단어 하나가 포함이 안되게 되었다면
        if(0 == --m[key])
        {
            m.erase(key);
            // 다시 조건을 만족할 때 까지 뒤를 밀어서 포함시켜본다.
            ++e;
            while(e < gems.size() && m.size() != all_gems.size())
            {
                ++m[gems[e]];
                if(m.size() == all_gems.size())break;
                ++e;
            }
        }
        // 앞을 하나 민 상태에서 e를 밀어보고 조건이 맞다면
        if(m.size() == all_gems.size())
        {
            // 원래부터 b가 가장 작을 때 부터 검사하기 때문에 길이가 같다면 먼저 검사한놈이 여기 처음온다.
            if(d > e - b)
            {
                answer[0]=b+1;
                answer[1]=e+1;
                d = e-b;
            }
        }
    }
    return answer;
}