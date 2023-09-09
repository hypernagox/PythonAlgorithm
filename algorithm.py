import sys
from collections import deque
sys.setrecursionlimit(1000000)
input = sys.stdin.readline
a = int(input())
b = int(input())
adj = [[] for _ in range(a)]
adj_rev = [[] for _ in range(a)]
inDeg = [0] * a
dists = [-1] * a
visited = [False] * a
for _ in range(b):
    u,v,w = map(int,input().split())
    adj[u-1].append((v-1,w))
    adj_rev[v-1].append((u-1,w))
    inDeg[v-1] += 1
start,end = map(int,input().split())
q = deque()
q.append((start-1,0))
dists[start-1] = 0
while q:
    node,cost = q.popleft()
    for n,d in adj[node]:
        inDeg[n]-=1
        dists[n] = max(dists[n], d + cost)
        if 0 == inDeg[n] :
            q.append((n,dists[n]))
print(dists[end-1])
res = 0
def dfs(cur):
    global res
    visited[cur] = True
    for next,cost in adj_rev[cur]:
        if dists[next] == dists[cur] - cost:
            res += 1
            if not visited[next]:
                dfs(next)
dfs(end-1)
print(res)



