#include <bits/stdc++.h>
using namespace std;
int solution(vector<vector<int>> data, int col, int row_begin, int row_end)
{
   sort(data.begin(),data.end(),[col](auto& a, auto& b){
       if(a[col-1]==b[col-1])return a.front() > b.front();
       return a[col-1] < b[col-1];
   });
    vector<int> res;
    for(int r = row_begin;r<=row_end;++r)
    {
        int acc = 0;
        for(const auto i : data[r-1])acc+=(i % r);
        res.emplace_back(acc);
    }
    int ans = res[0];
    for(int i=1;i<res.size();++i)ans ^= res[i];
    return ans;
}