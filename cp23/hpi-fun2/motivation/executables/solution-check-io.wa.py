n, l = map(int, input().split())
assert 1 <= n <= 10 ** 5
assert 1 <= l <= 10 ** 5
m = map(int, input().split())
assert len(m) == n
assert all(-10 ** 6 <= x <= 10 ** 6 for x in m)
p = map(int, input().split())
assert len(p) == n-1
assert all(1 <= x <= i for i, x in enumerate(p, 2))
print(-1)