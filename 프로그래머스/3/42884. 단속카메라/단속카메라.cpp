#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int solution(vector<vector<int>> routes)
{
    int answer = 1;
    vector<pi> vv;
    for (const auto& v : routes)
    {
        vv.emplace_back(v[1], v[0]);
    }
    sort(vv.begin(), vv.end());
    int cur_idx = 0;
	for (int i = 1; i < vv.size(); ++i)
	{
        if (vv[cur_idx].first < vv[i].second)
        {
            ++answer;
            cur_idx = i;
        }
	}
    return answer;
}

