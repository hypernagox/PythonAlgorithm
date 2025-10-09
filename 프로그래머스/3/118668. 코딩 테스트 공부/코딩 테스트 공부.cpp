#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int solution(int alp, int cop, vector<vector<int>> problems)
{
    // dp [i][j] -> 알고력 i 코딩력 j을 얻기 위해 걸리는 최단시간
    int max_al = alp;
    int max_cop = cop;
    for (const auto& p : problems)
    {
        // 최대로 필요한 알고력과 코딩력
        max_al = max(max_al, p[0]);
        max_cop = max(max_cop, p[1]);
    }
    if (alp >= max_al && cop >= max_cop)return 0;
    vector<vector<int>> dp(152, vector<int>(152, 1 << 20));
    dp[alp][cop] = 0; // 지금가지고있는 알고력 코딩력은 0비용이들음 
    for (int al = alp; al <= max_al; ++al)
    {
        for (int co = cop; co <= max_cop; ++co)
        {
            // 1 늘리려면 지금거에서 시간 1추가하거나 이전에 더 좋은 값 있거나
            dp[al][co + 1] = min(dp[al][co + 1], dp[al][co] + 1);
            dp[al + 1][co] = min(dp[al + 1][co], dp[al][co] + 1);
            for (const auto& p : problems)
            {
                // 문제를 풀 수 있다면
                if (p[0] <= al && p[1] <= co)
                {
                    const auto next_al = min(max_al, al + p[2]); // 넘어가는거 방지
                    const auto next_co = min(max_cop, co + p[3]);
                    // 기존에 알던거 또는 지금 최단값에서 필요시간 더한거
                    dp[next_al][next_co]
                        = min(dp[next_al][next_co], dp[al][co] + p[4]);
                }
            }
        }
    }
    return dp[max_al][max_cop];
}

