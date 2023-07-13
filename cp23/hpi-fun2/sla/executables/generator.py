import random
from pathlib import Path

random.seed(-8535914069351164421)

R_MIN = 1
R_MAX = 10**6
N_MIN = 2
N_MAX = 50
M_MIN = 0
M_MAX = 1000

def generate_random_test_case(n = None, m = None, r = None):
    n = n if n is not None else random.randint(N_MIN, N_MAX)
    max_possible_edges = n * (n-1) / 2
    m = m if m is not None else random.randint(M_MIN, min(max_possible_edges, M_MAX))

    nodes = list(range(1,n+1))
    edges = []
    for i in range(m):
        while True:
            a = random.choice(nodes)
            b = random.choice(nodes)
            # avoid self loops and duplicated edges
            if a == b or (a,b) in edges or (b,a) in edges:
                continue
            edges.append((a,b))
            break

    in_data = f"{n} {m}\n"
    for a,b in edges:
        edge_r = r if r is not None else random.randint(R_MIN, R_MAX)
        in_data += f'{a} {b} {edge_r}\n'

    return in_data

SAMPLE1 = '''\
4 4
1 2 100
1 3 300
2 4 500
3 4 1000\
'''

SAMPLE2 = '''\
7 9
1 2 1000
1 3 2000
4 1 500
5 2 420
3 5 1337
3 6 633
4 6 600
5 7 1500
6 7 2000\
'''

TESTCASES = [
    ('sample1', SAMPLE1, 'Sample 1'),
    ('sample2', SAMPLE2, 'Sample 2'),
    ('large', generate_random_test_case(50, 1000, R_MAX), 'Sample filling n,m bounds'),
]

for name, in_data, description in TESTCASES:
    Path(f'{name}.in').write_text(in_data + '\n')
    Path(f'{name}.desc').write_text(description + '\n')

for i in range(1, 21):
    print(f'Generating random case {i}')
    Path(f'random{i}.in').write_text(generate_random_test_case())
    Path(f'random{i}.desc').write_text(f'random testcase {i}\n')
