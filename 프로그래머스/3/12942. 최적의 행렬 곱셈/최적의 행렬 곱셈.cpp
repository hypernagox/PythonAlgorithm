#include <bits/stdc++.h>
using namespace std;
int memo[201][201];
vector<vector<int>> mats;
int GO(const int s, const int e)
{
    if(s == e)
    {
        return 0;
    }
    auto& ref = memo[s][e];
    if(ref)return ref;
    int res = 987654321;
    for(int i = s;i < e;++i)
    {
        const int a = GO(s, i); // s ~ i
        const int b = GO(i + 1, e); // i + 1 ~ e
        const int c = mats[s][0] * mats[i][1] * mats[e][1];
        res = min(res , a + b + c);
    }
    return ref = res;
}
int solution(vector<vector<int>> matrix_sizes) 
{
    mats.swap(matrix_sizes);
    return GO(0, mats.size() - 1);
}