import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000000)
n, m = map(int, input().split())

class UnionFind:
    def __init__(self,n):
        self.parents = [i for i in range(n)]
        self.rank = [0 for _ in range(n)]
    def find(self,u):
        if(self.parents[u] != u):
            self.parents[u] = self.find(self.parents[u])
        return self.parents[u]
    def union(self,u,v):
        if(u == v):
            return
        u = self.find(u)
        v = self.find(v)
        if(u == v):
            return
        if(self.rank[u] > self.rank[v]):
            u,v=v,u
        self.parents[v]=u
        if(self.rank[u] == self.rank[v]):
            self.rank[v] += 1


uf = UnionFind(n + 1)
for _ in range(m):
    x,a,b = map(int,input().split())
    if(0 == x):
        uf.union(a,b)
    else:
        if(uf.find(a) == uf.find(b)):
            print("YES")
        else:
            print("NO")