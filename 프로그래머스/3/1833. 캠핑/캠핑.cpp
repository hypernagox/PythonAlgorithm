#include <bits/stdc++.h>
using namespace std;
bool IsIntersect(pair<int,int> a,pair<int,int> b,pair<int,int> c)
{
    const auto min_y = min(a.second,b.second);
    const auto max_y = max(a.second,b.second);
    if(a.first < c.first && min_y < c.second && b.first > c.first && max_y > c.second)return true;
    return false;
}
int solution(int n, vector<vector<int>> data) 
{
    int answer = 0;
    vector<pair<int,int>> points;
    points.reserve(n);
    for(const auto& p : data)
    {
        points.emplace_back(p[0],p[1]);
    }
    sort(points.begin(),points.end());
    for(int i=0;i<n-1;++i)
    {
        const auto [x1,y1] = points[i];
        for(int j=i+1;j<n;++j)
        {
            const auto [x2,y2]=points[j];
            if(x1 == x2 || y1 == y2)continue;
            bool flag = true;
            for(int k=i+1;k<j;++k)
            {
                if(IsIntersect(points[i],points[j],points[k]))
                {
                    flag = false;
                    break;
                }
            }
            answer += flag;
        }
    }
    return answer;
}