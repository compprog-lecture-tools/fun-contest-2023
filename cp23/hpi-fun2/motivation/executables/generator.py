from pathlib import Path
import random

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


def basic_test1():
    test_case = (
        "7 10\n"
        "5 5 5 1 1 1 1\n"
        "1 1 3 3 2 2"
    )
    Path('basic_test1.in').write_text(test_case)


def basic_test2():
    test_case = (
        "11 20\n"
        "1 3 7 -2 2 -6 1 30 3 5 5\n"
        "1 1 1 3 3 3 4 4 8 8"
    )
    Path('basic_test2.in').write_text(test_case)


def basic_test3():
    test_case = (
        "14 15\n"
        "1 2 2 2 4 4 4 4 8 8 8 8 16 16\n"
        "1 1 1 3 3 4 4 6 6 8 8 10 10"
    )
    Path('basic_test3.in').write_text(test_case)


def basic_test4():
    test_case = (
        "6 5\n"
        "1 10 -8 -8 -8 -8\n"
        "1 2 2 2 2"
    )
    Path('basic_test4.in').write_text(test_case)


def large_increasing_chain():
    test_case = ""

    employees = 100_000
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

    employees = 1_000
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


def negative_only_test():
    test_case = ""

    hierarchical_levels = 8
    employees = 0
    for level in range(0, hierarchical_levels):
        employees += 3**level

    threshold = 20
    test_case += f"{employees} {threshold}\n"

    # Each person has negative motivational level
    for i in range(0, employees):
        test_case += f"{-i} "
    test_case += "\n"

    # I did not think about it at first, but actually there is
    #       (employees - 3**(hierarchical_levels-1))*3 = employees - 1
    # Each person has exactly 3 people under them.
    for i in range(0, employees - 3**(hierarchical_levels-1)):
        test_case += f"{i} {i} {i} "

    Path('negative_only.in').write_text(test_case)


def random_test_case(case_number):
    test_case = ""

    employees = 50_000
    threshold = random.randint(1, 1_000)

    test_case += f"{employees} {5*threshold}\n"

    for i in range(0, employees):
        motivational_level = random.randint(-threshold, threshold)
        test_case += f"{motivational_level} "
    test_case += "\n"

    test_case += "1 "
    for i in range(2, employees):
        boss = random.randint(1, i-1)
        test_case += f"{boss} "

    Path(f"random_test_case_{case_number}.in").write_text(test_case)


# Relatively simple trees
basic_test1()
basic_test2()
basic_test3()
basic_test4()

# Chain test cases: Tree, where each node has only one child
large_increasing_chain()
large_switching_chain()

# Each node has three children and each motivational level of -1
negative_only_test()

# Random test cases
random_test_case(1)
random_test_case(2)
random_test_case(3)