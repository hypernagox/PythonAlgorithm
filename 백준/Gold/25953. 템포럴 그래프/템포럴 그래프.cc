#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
constexpr const ll INF = 987654321;
int N, T, M, S, E;
int dist[1001][10000];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> T >> M >> S >> E;
	for (int i = 0; i < N; i++) dist[0][i] = INF;
	dist[0][S] = 0;
	for (int t = 0; t < T; t++) 
	{
		for (int i = 0; i < N; i++) dist[t + 1][i] = dist[t][i];
		for (int i = 0; i < M; i++)
		{
			int x, y, w; cin >> x >> y >> w;
			dist[t + 1][y] = min(dist[t + 1][y], dist[t][x] + w);
			dist[t + 1][x] = min(dist[t + 1][x], dist[t][y] + w);
		}
	}
	if (dist[T][E] < INF) cout << dist[T][E];
	else cout << -1;
}