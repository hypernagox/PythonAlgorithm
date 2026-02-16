#include <bits/stdc++.h>
using namespace std;
int solveLinear(int L, int R, const vector<int>& a) 
{ // [L..R]
    int prev2 = 0; // dp[i-2]
    int prev1 = 0; // dp[i-1]
    for (int i = L; i <= R; ++i) {
        int cur = max(prev1, prev2 + a[i]);
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

int solution(vector<int> sticker) 
{
    int n = (int)sticker.size();
    if (n == 1) return sticker[0];

    // A) 0 안 고름 => [1..n-1]
    int a = solveLinear(1, n - 1, sticker);

    // B) 0 고름 => sticker[0] + [2..n-2]
    int b = sticker[0] + (n >= 3 ? solveLinear(2, n - 2, sticker) : 0);

    return max(a, b);
}
