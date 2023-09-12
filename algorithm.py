import sys
from collections import deque
input = sys.stdin.readline
n,m = map(int,input().split())
adj = [[] for _ in range(n)]
visited = [0] * n
for _ in range(m):
    u,v = map(int,input().split())
    adj[u-1].append(v-1)
    adj[v-1].append(u-1)
def bfs (u):
    pq = deque([u])
    while pq:
        cur = pq.popleft()
        for next in adj[cur]:
            if visited[next] == 0:
                visited[next] = visited[cur] + 1
                pq.append(next)
    return sum(visited)
res = [0] * n
minval = sys.maxsize
for i in range(n):
    res[i] = bfs(i)
    minval = min(minval,res[i])
    visited = [0] * n
for i in range(n):
    if res[i] == minval:
        print(i + 1)
        exit()




