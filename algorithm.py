import sys
from collections import deque
input = sys.stdin.readline
n = int(input().strip())

costs = [0] * n
inDegree = [0] * n
res = [0] * n
q = deque()
adj = [[] for _ in range(n)]
for i in range(n):
    data = list(map(int, input().strip().split()))
    costs[i] = data[0]
    for j in data[1:]:
        if j == -1:
            break
        adj[j - 1].append(i)
        inDegree[i] += 1
    if 0 == inDegree[i]:
        q.append(i)
while q:
    node = q.popleft()
    for next in adj[node]:
        inDegree[next] -= 1
        if 0 == inDegree[next]:
            q.append(next)
        res[next] = max(res[next] , res[node] + costs[node])
for i in range(n):
    print(res[i] + costs[i])








