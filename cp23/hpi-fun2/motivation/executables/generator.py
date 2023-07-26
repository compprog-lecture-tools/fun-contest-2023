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


def binary_tree_two_layers():
    test_case = (
        "7 10\n"
        "5 5 5 1 1 1 1\n"
        "1 1 3 3 2 2"
    )
    Path('binary_tree_two_layers.in').write_text(test_case)


def single_unreachable_with_negatives():
    test_case = (
        "11 20\n"
        "1 3 7 -2 2 -6 1 30 3 5 5\n"
        "1 1 1 3 3 3 4 4 8 8"
    )
    Path('single_unreachable_with_negatives.in').write_text(test_case)


def exponential_weights():
    test_case = (
        "14 15\n"
        "1 2 2 2 4 4 4 4 8 8 8 8 16 16\n"
        "1 1 1 3 3 4 4 6 6 8 8 10 10"
    )
    Path('exponential_weights.in').write_text(test_case)


def single_node_bottleneck():
    test_case = (
        "6 5\n"
        "1 10 -8 -8 -8 -8\n"
        "1 2 2 2 2"
    )
    Path('single_node_bottleneck.in').write_text(test_case)


def large_increasing_chain():
    test_case = ""

    employees = 100_000
    threshold = 50_000
    test_case += f"{employees} {threshold}\n"

    levels = []
    for i in range(0, employees):
        levels.append(1)
    test_case += " ".join([str(x) for x in levels]) + "\n"

    bosses = []
    for i in range(1, employees):
        bosses.append(i)
    test_case += " ".join([str(x) for x in bosses])

    Path('large_increasing_chain.in').write_text(test_case)


def switching_chain():
    test_case = ""

    employees = 1_000
    threshold = 1
    test_case += f"{employees} {threshold}\n"

    levels = []
    for i in range(0, employees):
        if i % 2 == 0:
            levels.append(1)
        else:
            levels.append(-1)
    test_case += " ".join([str(x) for x in levels]) + "\n"

    bosses = []
    for i in range(1, employees):
        bosses.append(i)
        test_case += f"{i} "
    test_case += " ".join([str(x) for x in bosses]) + "\n"

    Path('switching_chain.in').write_text(test_case)


def negative_only_test():
    test_case = ""

    hierarchical_levels = 8
    employees = 0
    for level in range(0, hierarchical_levels):
        employees += 3**level

    threshold = 20
    test_case += f"{employees} {threshold}\n"

    # Each person has negative motivational level
    levels = []
    for i in range(0, employees):
        levels.append(-i)
    test_case += " ".join([str(x) for x in levels]) + "\n"

    # I did not think about it at first, but actually there is
    #       (employees - 3**(hierarchical_levels-1))*3 = employees - 1
    # Each person has exactly 3 people under them.
    bosses = []
    for i in range(1, employees - 3**(hierarchical_levels-1)):
        bosses.extend([i, i, i])
    test_case += " ".join([str(x) for x in bosses]) + "\n"

    Path('negative_only.in').write_text(test_case)


def random_test_case(case_number):
    test_case = ""

    employees = 100_000
    threshold = random.randint(1, 1_000)

    test_case += f"{employees} {5*threshold}\n"

    levels = []
    for i in range(0, employees):
        motivational_level = random.randint(-threshold, threshold)
        levels.append(motivational_level)
    test_case += " ".join([str(x) for x in levels]) + "\n"

    bosses = [1]
    for i in range(2, employees):
        boss = random.randint(1, i-1)
        bosses.append(boss)
    test_case += " ".join([str(x) for x in bosses]) + "\n"

    Path(f"random_test_case_{case_number}.in").write_text(test_case)


# Relatively simple trees
binary_tree_two_layers()
single_unreachable_with_negatives()
exponential_weights()
single_node_bottleneck()

# Chain test cases: Tree, where each node has only one child
large_increasing_chain()
switching_chain()

# Each node has three children and each motivational level of -1
negative_only_test()

# Random test cases
for i in range(1,4):
    random_test_case(i)