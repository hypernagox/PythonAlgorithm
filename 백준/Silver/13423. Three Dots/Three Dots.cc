#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        int N; cin >> N;
        vector<long long> X(N);
        for (int i = 0; i < N; ++i) cin >> X[i];

        sort(X.begin(), X.end());

        long long ans = 0;
        for (int j = 1; j + 1 < N; ++j) {          // X[j]를 가운데(b)로 고정
            int i = j - 1, k = j + 1;
            const long long target = 2LL * X[j];   // 비교는 long long으로
            while (i >= 0 && k < N) {
                long long s = X[i] + X[k];
                if (s == target) {
                    ++ans;  // (i, j, k) 한 쌍 발견
                    --i;    // 더 왼쪽, 더 오른쪽으로 확장
                    ++k;
                }
                else if (s < target) {
                    ++k;    // 간격을 키워야 함
                }
                else {
                    --i;    // 간격을 줄여야 함
                }
            }
        }
        cout << ans << '\n';
    }
}