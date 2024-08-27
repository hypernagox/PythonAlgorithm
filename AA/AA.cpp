#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Mat {
	int r, c;
};
int dp[500][500];
Mat m[500];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		Mat mat; cin >> mat.r >> mat.c;
		m[i] = mat;
	}
	for (int i = 1; i < n; ++i) {
		for (int dy = 0; dy + i < n; ++dy) {
			const int dx = dy + i;
			dp[dy][dx] = 1 << 30;
			for (int k = dy; k < dx; ++k) {
				dp[dy][dx] = min(dp[dy][dx], dp[dy][k] + dp[k+1][dx] + m[dy].r * m[k].c * m[dx].c);
			}
		}
	}
	cout << dp[0][n - 1];
}