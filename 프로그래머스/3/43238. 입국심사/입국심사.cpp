#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
bool Check(const int human,const vector<int>& times, const long long mid)
{
    long long sum = 0;
    for(const auto t:times)
    {
        sum += (mid / t);
        if(sum >= human)return true;
    }
    return false;
}
long long solution(int n, vector<int> times) 
{
    long long answer = 1;
    long long b = 1;
    long long e = (long long)std::numeric_limits<long long>::max() / 2;
    while(b < e)
    {
        const long long mid = b + (e - b) / 2LL;
        if(Check(n,times,mid))
        {
            // 가능 -> 줄여봄
            e = mid;
        }
        else
        {
            // 불가능 -> 올림
            b = mid + 1;
            answer = b;
        }
    }
    return answer;
}