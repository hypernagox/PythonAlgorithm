#include <bits/stdc++.h>
using namespace std;
bool row_flip[10];
bool col_flip[10];
int n;
int m;
vector<vector<int>> s;
vector<vector<int>> e;
int ans = 987654321;
void GO(const int idx)
{
    if(idx == n)
    {
        for(int i=0;i<m;++i)
        {
            int val = s[0][i];
            if(row_flip[0])val = !val;
            col_flip[i] = (val != e[0][i]);
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                int val = s[i][j];
                if(row_flip[i])val = !val;
                if(col_flip[j])val = !val;
                if(val != e[i][j])return;
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) cnt += row_flip[i];
        for (int j = 0; j < m; ++j) cnt += col_flip[j];
        ans = min(ans,cnt);
        return;
    }
    // 뒤집기
    row_flip[idx] = 1;
    GO(idx+1);
    // 안뒤집기
    row_flip[idx] = 0;
    GO(idx+1);
}
int solution(vector<vector<int>> beginning, vector<vector<int>> target) 
{
    n = beginning.size();
    m = beginning.back().size();
    s.swap(beginning);
    e.swap(target);
    GO(0);
    if(ans == 987654321)return -1;
    else return ans;
}