n, l = map(int, input().split())
m = list(map(int, input().split()))
adj = [[] for _ in range(n)]
for subordinate, boss in enumerate([int(x) - 1 for x in input().split()], start=1):
    m[subordinate] = m[boss] + m[subordinate] if m[boss] <= l else l + 1
    adj[boss].append(subordinate)
unmotivatable = []
dp = n * [0]
for employee in range(n - 1, -1, -1):
    if m[employee] > l:
        unmotivatable.append(employee)
        continue
    dp[employee] = max(1, -1 + sum([dp[x] for x in adj[employee]]))
print(dp[0], len(unmotivatable))

