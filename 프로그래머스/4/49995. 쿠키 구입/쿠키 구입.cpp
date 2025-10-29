#include <string>
#include <vector>
using namespace std;
int solution(vector<int> cookie)
{
    int ans = 0;
    for(int i=0;i<cookie.size() - 1;++i)
    {
        int l = i;
        int r = l + 1;
        int left = cookie[l];
        int right = cookie[r];
        for(;;)
        {
            if(l < 0 || r >= cookie.size())break;
            if(left == right) ans = max(ans,left);
            if(left <= right)
            {
                if(l <=0)break;
                left+= cookie[--l];
            }
            else if(left >= right)
            {
                if(r>=cookie.size()-1)break;
                right += cookie[++r];
            }
            
        }
    }
    return ans;
}