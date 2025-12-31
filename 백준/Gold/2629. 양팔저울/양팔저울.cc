#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
constexpr const int INF = 987654321;
int n;
int k;
vector<int> chu;
vector<int> orb;
bool visited[80002];
int memo[62][80002];
int GO(const int i,const int left,const int right)
{
	auto& ref = memo[i][abs(left - right)];
	if (-1 != ref)return ref;
	ref = visited[abs(left - right)] = true;
	if (i == chu.size())return 0;
	
	// 왼쪽에 놓기
	ref |= GO(i + 1, left + chu[i], right); 

	// 오른쪽에 놓기
	ref |= GO(i + 1, left, right + chu[i]);

	// 안놓기
	ref |= GO(i + 1, left, right);
	return ref;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int a; cin >> a;
			chu.emplace_back(a);
		}
		cin >> k;
		for (int i = 0; i < k; ++i)
		{
			int a; cin >> a;
			orb.emplace_back(a);
		}
		memset(memo, -1, sizeof(memo));
		GO(0, 0, 0);
		for (int j = 0; j < k; ++j)
		{
			if (visited[orb[j]])
			{
				cout << 'Y' << ' ';
			}
			else
			{
				cout << 'N' << ' ';
			}
		}
		cout << '\n';
		chu.clear();
		orb.clear();
	}
}