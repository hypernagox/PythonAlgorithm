import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000)
a,b = map(int,input().split())
adj = [[] for _ in range(a)]
visited = [False] * a
for _ in range(b):
    u,v = map(int,input().split())
    adj[v-1].append(u-1)
    adj[u-1].append(v-1)
def is_eulerian():
    odd_count = sum(1 for node in adj if len(node) % 2 == 1)
    if odd_count == 0 or odd_count == 2:
        return True
    return False
def dfs(node):
    visited[node] = True
    for next in adj[node]:
        if not visited[next]:
            dfs(next)
def can_visit():
    global visited
    for i in range(a):
        dfs(i)
        if all(visited):
            return True
        visited = [False] * a
    return False
if is_eulerian() and can_visit():
    print("YES")
else:
    print("NO")