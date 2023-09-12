import sys
input = sys.stdin.readline
n,m = map(int,input().split())
dists = [[sys.maxsize] * n for _ in range(n)]
for _ in range(m):
    u,v = map(int,input().split())
    dists[u-1][v-1] = dists[v-1][u-1] = 1
for k in range(n):
    for u in range(n):
        for v in range(n):
            dists[u][v] = min(dists[u][v],dists[u][k] + dists[k][v])
minval = sys.maxsize
res = [0] * n
for i in range(n):
    res[i] = sum(dists[i])
    minval = min(minval,res[i])
for i in range(n):
    if minval == res[i]:
        print(i+1)
        exit()


