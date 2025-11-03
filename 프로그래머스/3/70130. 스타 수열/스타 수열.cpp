#include <string>
#include <vector>
using namespace std;
int cnt[500001];
int solution(std::vector<int> a)
{
    int answer = 0;
    for(const auto i: a)++cnt[i];
    for(int i=0;i<500001;++i)
    {
        if(cnt[i] == 0)continue;
        if(cnt[i] <= answer)continue;
        int res = 0;
        for(int j=0;j<a.size()-1;++j)
        {
            if((a[j] == i || a[j + 1] == i) && a[j] != a[j+1])
            {
                ++res;
                ++j;
            }
        }
        answer = max(answer,res);
    }
    return answer * 2;
}