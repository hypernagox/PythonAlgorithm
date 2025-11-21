#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;
long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
	long long ans = (long long)(10e9 * 2 * 10e5 * 2);
	const auto num = (int)t.size();
	const long long SUM = a + b;
	long long l = 0;
	long long e = (long long)(10e9 * 2 * 10e5 * 2);
	while(l <= e) {
		long long cur_time = (l + e) / 2;
		long long gold = 0;
		long long silver = 0;
		long long sum2 = 0;
		for (int i = 0; i < num; ++i) {
			const auto time2 = t[i] * 2;
			auto dd = lldiv(cur_time, time2);
			dd.quot += (dd.rem >= (long long)t[i]);
			const auto cnt = (long long)w[i] * dd.quot;
			gold += min((long long)g[i], cnt);
			silver += min((long long)s[i], cnt);
			sum2 += min((long long)g[i] + (long long)s[i], cnt);
		}
		if (SUM <= sum2 && a <= gold && b <= silver) {
			e = cur_time - 1;
			ans = min(cur_time, ans);
		}
		else {
			l = cur_time + 1;
		}
	}
	return ans * 1;
}