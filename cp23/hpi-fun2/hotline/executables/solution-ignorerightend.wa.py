from itertools import chain
l,r = map(int, input().split())
print(next(filter(lambda x: len(set(list(str(x))))==len(str(x)), chain(range(l,r), [-1])))) # in correct solution, this should be range(l, r+1)
