#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(vector<int> sequence)
{
    long long answer = 0;
    vector<int> v1,v2;
    v1.reserve(sequence.size());
    v2.reserve(sequence.size());
    int s = 1;
    for(const auto i:sequence)
    {
        v1.emplace_back(i*s);
        s *= -1;
        v2.emplace_back(i*s);
    }
    long long res = -987654321;
    for(const auto i: v1)
    {
        res = max(res,0LL)+i;
        answer=max(answer,res);
    }
    res = -987654321;
    for(const auto i: v2)
    {
        res = max(res,0LL)+i;
        answer=max(answer,res);
    }
    return answer;
}