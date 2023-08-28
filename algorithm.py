import sys
input = sys.stdin.readline
n = int(input())
m = int(input())
dist = [[float("INF")] * n for _ in range(n) ]
for i in range(n):
    dist[i][i]=0
for _ in range(m):
    u,v,w = map(int,input().split())
    dist[u-1][v-1] = min(dist[u-1][v-1],w)
for k in range(n):
    for i in range(n):
        for j in range(n):
            dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j])
for i in range(n):
    for j in range(n):
        if float("INF") == dist[i][j]:
            print(0,end = " ")
        else:
            print(dist[i][j],end = " ")
    print()





