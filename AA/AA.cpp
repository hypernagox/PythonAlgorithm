#include <iostream>
using namespace std;
uint64_t dp[1000001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 
    int n; cin >> n;
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n; ++i) {
        dp[i] = ((i - 1) * (dp[i - 1] + dp[i - 2])) % 1000000000;
    }
    cout << dp[n];
}
