import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000)
class DisjointSet:
    def __init__(self,n):
        self.parent = [ i for i in range(n)]
        self.rank = [0] * n
    def Find(self,u):
        if self.parent[u] == u:
            return u
        self.parent[u] = self.Find(self.parent[u])
        return self.parent[u]
    def Union(self,u,v):
        u = self.Find(u)
        v = self.Find(v)
        if u == v:
            return False
        if self.rank[u] > self.rank[v]:
            u,v=v,u
        self.parent[u] = v
        if self.rank[u] == self.rank[v]:
            self.rank[v] += 1
        return True
n = int(input())
uf = DisjointSet(n)
Edges = []
sum = 0
for i in range(n):
    temp = input().strip()
    for j in range(n):
        if temp[j] == '0':
            continue
        x = 0
        if temp[j].isupper():
            x = ord(temp[j]) - ord('A') + 27
        else:
            x = ord(temp[j]) - ord('a') + 1
        sum += x
        if i != j:
           Edges.append((x,i,j))
Edges.sort()
res = 0
cnt = 0
for w,u,v in Edges:
    if uf.Union(u,v):
        res += w
        cnt += 1
    if n-1 == cnt:
        break
if n-1 == cnt:
    print(sum - res)
else:
    print(-1)


