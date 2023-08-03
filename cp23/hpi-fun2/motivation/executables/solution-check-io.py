n, l = map(int, input().split())
assert 1 <= n <= 10 ** 5
assert 1 <= l <= 10 ** 5
m = list(map(int, input().split()))
assert len(m) == n
assert all(-10 ** 6 <= x <= 10 ** 6 for x in m)
p = list(map(int, input().split()))
assert len(p) == n-1
assert all(1 <= x <= i for i, x in enumerate(p, 1))

adj = [[] for _ in range(n)]
for subordinate, boss in enumerate(p, start=1):
    boss -= 1
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

