from pathlib import Path

SAMPLES = [
["sample1", """11 20
2 5 3 7 2 1 10 4 1 8 2
1 2 2 2 5 5 1 8 8 8"""],
["sample2", """5 7
1 5 10 -2 -2
1 1 3 3"""],
["sample3", """5 7
8 5 10 -2 -2
1 1 3 3"""]
]

for name, sample in SAMPLES:
    Path(name + ".in").write_text(sample + '\n')

def large_increasing_chain():
    test_case = ""

    employees = 50_000
    threshold = 5_000
    test_case += f"{employees} {threshold}\n"

    for i in range(0, employees):
        test_case += "1 "
    test_case += '\n'

    for i in range(1, employees):
        test_case += f"{i} "
    test_case += '\n'

    Path('large_increasing_chain.in').write_text(test_case)


def large_switching_chain():
    test_case = ""

    employees = 50_000
    threshold = 1
    test_case += f"{employees} {threshold}\n"

    for i in range(0, employees):
        if i % 2 == 0:
            test_case += "1 "
        else:
            test_case += "-1 "
    test_case += '\n'

    for i in range(1, employees):
        test_case += f"{i} "
    test_case += '\n'

    Path('large_switching_chain.in').write_text(test_case)


large_increasing_chain()
large_switching_chain()
