#include <string>
#include <vector>

using namespace std;
bool Check(const vector<int>& stones,const int k,const int mid)
{
    int cnt = 0;
    for(const auto s : stones)
    {
        const auto val = max(0,s-mid); // 사람이 mid명
        if(val == 0)
        {
            ++cnt;
            if(cnt == k)
            {
                return false;
            }
        }
        else
        {
            cnt =0;
        }
    }
    return true;
}
int solution(vector<int> stones, int k)
{
    int answer = 0;
    int l=1;
    int r=INT32_MAX;
    while(l<r)
    {
        const auto mid = (l+r)/2;
        if(Check(stones,k,mid))
        {
            l = mid + 1;
            answer = l;
        }
        else
        {
            r = mid;
        }
    }
    return answer;
}