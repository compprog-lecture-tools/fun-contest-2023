import random
from pathlib import Path

random.seed(-8535914069351164421)

R_MIN = 1
R_MAX = 10**6
N_MIN = 2
N_MAX = 50
M_MIN = 0
M_MAX = 1000

def generate_random_test_case(n, m, r = None):
    max_possible_edges = n * (n-1) // 2

    assert(m <= max_possible_edges)

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

NO_EDGES = '2 0\n'

NO_PATH = '''\
3 1
1 2 1337\
'''

TESTCASES = [
    ('sample1', SAMPLE1, 'Sample 1'),
    ('sample2', SAMPLE2, 'Sample 2'),
    ('large', generate_random_test_case(N_MAX, M_MAX, R_MAX), f'Maximum input n = {N_MAX}, m = {M_MAX}, r = {R_MAX}'),
    ('no-edges', NO_EDGES, 'Sample without any edges m = 0'),
    ('no-path', NO_PATH, 'Sample with edges but no s-t-path'),
]

for name, in_data, description in TESTCASES:
    Path(f'{name}.in').write_text(in_data + '\n')
    Path(f'{name}.desc').write_text(description + '\n')

for i in range(1, 21):
    print(f'Generating random case {i}')

    n = random.randint(N_MIN, N_MAX)
    max_possible_edges = n * (n-1) // 2
    m = min(max_possible_edges, random.randint(M_MIN, M_MAX))

    Path(f'random{i}.in').write_text(generate_random_test_case(n, m))
    Path(f'random{i}.desc').write_text(f'random testcase {i}: n = {n}, m = {m}\n')
