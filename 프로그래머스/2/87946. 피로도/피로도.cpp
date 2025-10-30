#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) 
{
    vector<pair<int,int>> d;
    for(const auto& v:dungeons)
    {
        d.emplace_back(v[0],v[1]);
    }
    sort(d.begin(),d.end());
    int ans = 0;
    do
    {
        int K =k;
        int cnt = 0;
        for(const auto [min_piro, somo_piro]:d)
        {
            if(K >= min_piro)
            {
                K -= somo_piro;
                ++cnt;
            }
        }
        ans = max(ans , cnt);
    }while(next_permutation(d.begin(),d.end()));
    return ans;
}