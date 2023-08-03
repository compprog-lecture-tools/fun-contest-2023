n, l = map(int, input().split())
m = list(map(int, input().split()))
adj = [[] for _ in range(n)]
for s, b in enumerate([int(x) - 1 for x in input().split()], start=1):
    m[s] = m[b] + m[s] if m[b] <= l else l + 1
    adj[b].append(s)
ans = 0
dp = n * [0]
for e in range(n - 1, -1, -1):
    ans += m[e] > l
    dp[e] = int(m[e] <= l) and max(1, -1 + sum([dp[x] for x in adj[e]]))
print(dp[0], ans)

