import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)
N = int(input())
tree = [[] for _ in range(N)]
for _ in range(N - 1):
    a,b = map(int,input().split())
    tree[a-1].append(b-1)
    tree[b-1].append(a-1)
visited = [False] * N
parent = [0] * N
def dfs(n):
    visited[n] = True
    for next in tree[n]:
        if visited[next]:
            continue
        parent[next] = n
        dfs(next)
dfs(0)
for i in range(1,N):
    print(parent[i] + 1)
