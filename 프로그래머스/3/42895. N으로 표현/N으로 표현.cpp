#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
int solution(int N, int number) 
{
    map<int,set<int>> m;
    int answer = 0;
    m[1].emplace(N);
    for(int i=2;i<=10;++i)
    {
        for(int j= i -1;j>= 1;--j)
        {
            for(const auto a1:m[j])
            {
                for(const auto a2:m[i-j])
                {
                    m[i].emplace(a1*a2);
                    m[i].emplace(a1+a2);
                    m[i].emplace(a1-a2);
                    auto aa=a1;
                    auto bb=a2;
                    if(aa<bb)swap(aa,bb);
                    if(aa != 0 && bb!=0) m[i].emplace(aa/bb);
                }
            }
        }
       auto res = N;
       auto nn = i - 1;
       while(nn--)
       {
           res *= 10;
           res += N;
       }
       m[i].emplace(res);
    }
    for(int i=1;i<=10;++i)
    {
        if(i > 8)return -1;
        if(m[i].count(number))return i;
    }
    return answer;
}