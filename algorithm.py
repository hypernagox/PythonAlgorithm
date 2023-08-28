import sys
input = sys.stdin.readline

n,m = map(int,input().split())
dists = [float("INF")] * n
adj=[]
for _ in range(m):
    u, v, w = map(int,input().split())
    adj.append((u - 1,v - 1,w))
dists[0] = 0
ok=True
for _ in range(n-1):
    for u,v,w in adj:
        if float("INF") == dists[u]:continue
        if(dists[v] > dists[u] + w):
            dists[v] = dists[u] + w
for u,v,w in adj:
    if float("INF") == dists[u]: continue
    if (dists[v] > dists[u] + w):
        ok = False
if ok:
    for i in dists[1:]:
        if float("INF") == i : print(-1)
        else: print(i)
else:
    print(-1)






