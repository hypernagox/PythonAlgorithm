#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
struct Data
{
	int start_time;
	int end_time;
	int type;
	const auto operator<(const Data& d)const noexcept {
		if (end_time == d.end_time)return start_time > d.start_time;
		return end_time > d.end_time;
	}
};
int Time2Int(const string& str)
{
	return stoi(str.substr(0, 2)) * 60 + stoi(str.substr(3, 2));
}
void INPUT_DATA(int n, vector<Data>& v,const int k,const int type)
{
	while (n--)
	{
		string start, end; cin >> start >> end;
		v.emplace_back(Time2Int(start), Time2Int(end) + k, type);
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int t; cin >> t;
	int CASE = 1;
	while (t--)
	{
		vector<Data> v;
		int k, na, nb;
		cin >> k >> na >> nb;
		INPUT_DATA(na, v, k, 0);
		INPUT_DATA(nb, v, k, 1);
		sort(v.begin(), v.end(), [](Data& a, Data& b) {
			return a.start_time < b.start_time;
			});
		priority_queue<Data> pq[2];
		int cnt[2] = {};
		for (const auto [s, e, type] : v)
		{
			if (!pq[type].empty() && pq[type].top().end_time <= s)
			{
				pq[type].pop();
			}
			else
			{
				++cnt[type];
			}
			pq[!type].emplace(Data{ s,e,type });
		}
		cout << "Case #" << CASE++ << ": " << cnt[0] << ' ' << cnt[1] << '\n';
	}
}