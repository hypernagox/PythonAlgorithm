#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
constexpr const int MAX_VAL = 987654321;
const string p[3]
{
	"pi","ka","chu"
};
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str; cin >> str;
	string s;
	for (const auto ch : str)
	{
		s.push_back(ch);
		if (s.size() < 2)continue;
		if (s == p[0] || s == p[1] || s == p[2])
		{
			s.clear();
		}
		else
		{
			if (s.size() == 3)break;
		}
	}
	if (s.empty())cout << "YES";
	else cout << "NO";
}
