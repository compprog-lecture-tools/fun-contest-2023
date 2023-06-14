l, r = map(int, input().split())
for x in range(l, r + 1):
    st = str(x)
    se = set(st)
    if len(st) == len(se):
        print(x)
        exit(0)
print(-1)
