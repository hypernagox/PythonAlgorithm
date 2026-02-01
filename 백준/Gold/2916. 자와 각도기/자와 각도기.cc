#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int arr[11];
int n, m;
bool visited[360];
void GO(const int cur_angle)
{
	if (visited[cur_angle])return;
	visited[cur_angle] = 1;
	for (int i = 0; i < n; ++i)
	{
		const auto a1 = (cur_angle + arr[i]) % 360;
		const auto a2 = (cur_angle - arr[i] + 360) % 360;
		GO(a1); GO(a2);
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)cin >> arr[i];
	//for (int i = 0; i < n; ++i)GO(arr[i]);
	GO(0);
	while (m--)
	{
		int a; cin >> a;
		cout << (visited[a] ? "YES" : "NO") << '\n';
	}
}