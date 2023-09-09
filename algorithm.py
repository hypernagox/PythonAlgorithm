import sys
input = sys.stdin.readline
a,b,c,d = map(int,input().split())
edges = [0] * d
bestDists = [-float("INF")] * a
visited = [False] * a
adj = [[] for _ in range(a)]
for i in range(d):
    u,v,w = map(int,input().split())
    edges[i] = (u,v,w)
    adj[u].append(v)
benefits = [int(x) for x in input().split()]
bestDists[b] = benefits[b]
res = benefits[b]
def dfs(cur):
    if cur == c :
        return True
    visited[cur] = True
    can_visit = False
    for next in adj[cur]:
        if not visited[next]:
            can_visit |= dfs(next)
    return can_visit
for _ in range(a-1):
    for u,v,w in edges:
        if -float("INF") == bestDists[u]:
            continue
        if bestDists[v] < bestDists[u] - w + benefits[v]:
            bestDists[v] = bestDists[u] - w + benefits[v]
if -float("INF") == bestDists[c]:
    print("gg")
    sys.exit()
for u, v, w in edges:
    if -float("INF") == bestDists[u]:
        continue
    if bestDists[v] < bestDists[u] - w + benefits[v]:
        if dfs(v):
            print("Gee")
            sys.exit()
        else:
            visited = [False] * a
print(bestDists[c])
