c, n = map(int, input().split())

adj = [[] for i in range(n)] 
for _ in range(n-1):
    a, b, d = map(int, input().split())
    assert(0 <= a < n and 0 <= b < n)
    adj[a].append((b, d))
    adj[b].append((a, d))

def bfs(s):
    q = [s]
    dist = [-1] * n
    dist[s] = 0
    while len(q) > 0:
        v = q[-1]
        q.pop()
        for e in adj[v]:
            if dist[e[0]] >= 0:
                continue
            dist[e[0]] = dist[v] + e[1]
            q.append(e[0])
    far = max(range(n), key=lambda i: dist[i])
    assert min(dist) == 0
    return far, dist[far]


a, da = bfs(0)
b, db = bfs(a)

print(["YES:", "NO:"][db > c], db)
