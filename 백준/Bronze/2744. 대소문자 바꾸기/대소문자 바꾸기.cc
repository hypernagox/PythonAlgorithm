#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str; cin >> str;
	for (auto& ch : str)
	{
		if (isupper(ch))
		{
			ch = tolower(ch);
		}
		else
		{
			ch = toupper(ch);
		}
	}
	cout << str;
}