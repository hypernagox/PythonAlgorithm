#include <bits/stdc++.h>
using namespace std;
pair<int,int> Rotate(const int r,const int c, const int h)
{
    return {c,h-1-r};
}
vector<vector<int>> GetRotateKey(const vector<vector<int>>& key)
{
    vector<vector<int>> temp(key.size(),vector<int>(key.back().size(),0));
    for(int i=0;i<key.size();++i)
    {
        for(int j=0;j<key.back().size();++j)
        {
            if(key[i][j])
            {
                const auto [y,x]=Rotate(i,j,key.size());
                temp[y][x]=1;
            }
        }
    }
    return temp;
}
void ApplyKey(
    const int off_y,
    const int off_x,
    const vector<vector<int>>& key,
    vector<vector<int>>& l,
    const int sign)
{
    for(int i=0;i<key.size();++i)
    {
        for(int j=0;j<key.back().size();++j)
        {
            l[off_y+i][off_x+j] += key[i][j] * sign;
        }
    }
}
bool Check(const int n, const vector<vector<int>>& l)
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(l[i+n][j+n] != 1)return false;
        }
    }
    return true;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    const auto n = lock.size();
    vector<vector<int>> l(3*n,vector<int>(3*n,0));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            l[i+n][j+n]=lock[i][j];
        }
    }
    for(int rot = 0;rot < 4; ++rot)
    {
        for(int y = 0;y<2*n;++y)
        {
            for(int x = 0;x<2*n;++x)
            {
                ApplyKey(y,x,key,l,1);
                if(Check(n,l))
                {
                    return true;
                }
                ApplyKey(y,x,key,l,-1);
            }
        }
        key = GetRotateKey(key);
    }
    return false;
}