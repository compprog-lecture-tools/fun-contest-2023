w, h = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(h)]
ans = 0
for i in range(h):
    b = w * [0]
    for row in a[i:]:
        for j, x in enumerate(row):
            b[j] += x
        last = 0
        for x in b:
            last = max(last + x, 0)
            ans = max(ans, last)
print(ans)

