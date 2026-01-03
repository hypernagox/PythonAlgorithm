#include <bits/stdc++.h>
using namespace std;
int GO(const int n, const int plus_count)
{
    if((log(n)/log(3))*2 < plus_count)return 0;
    if(n == 3 && plus_count == 2) return 1; 
    int res = 0;
    if(n % 3 == 0 && plus_count >= 2)
    {
        res += GO(n/3,plus_count - 2);
    }
    res += GO(n-1,plus_count + 1);
    return res;
}
int solution(int n) 
{
    return GO(n-2,2);
}