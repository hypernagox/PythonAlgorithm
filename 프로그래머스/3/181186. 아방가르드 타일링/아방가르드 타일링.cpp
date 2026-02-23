#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr const ll MOD = 1000000007;
int solution(int n) {
    // 기저 조건 처리
    if (n == 1) return 1;
    if (n == 2) return 3;
    if (n == 3) return 10;
    
    // N 최대 크기만큼 dp 배열 할당
    vector<long long> dp(n + 1, 0);
    
    // 초기값 세팅
    dp[0] = 1;  // 아무것도 안 채우는 경우의 수 1
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 10;
    
    // 4부터 N까지 점화식을 이용해 바텀업으로 계산
    for (int i = 4; i <= n; i++) {
        // long long 형이므로 오버플로우 발생하지 않음 (최대 약 100억)
        long long next_val = dp[i-1] + dp[i-2] * 2 + dp[i-3] * 6 + dp[i-4];
        long long minus_val = (i >= 6) ? dp[i-6] : 0;
        
        // C++에서 모듈러 뺄셈 시 음수 방지 로직
        dp[i] = (next_val - minus_val) % MOD;
        if (dp[i] < 0) {
            dp[i] += MOD;
        }
    }
    
    return dp[n];
}