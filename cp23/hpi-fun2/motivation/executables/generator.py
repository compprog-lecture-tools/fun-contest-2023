from pathlib import Path
import random

INPUT_LIMIT = 100_000

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

Path("sample1.in").write_text(SAMPLES[0][1])
Path("sample1.desc").write_text("Basic test case; no unreachable nodes.")

Path("sample2.in").write_text(SAMPLES[1][1])
Path("sample2.desc").write_text("Basic tree case; using negative weights, exceeding weight subtree.")

Path("sample3.in").write_text(SAMPLES[2][1])
Path("sample3.desc").write_text("No reachable children, bottleneck at root; single coach needed.")


def single_parent_single_child():
    filename = "single_parent_single_child"

    test_case = (
        "2 20\n"
        "10 10\n"
        "1"
    )
    Path(filename + ".in").write_text(test_case)
    Path(filename + ".desc").write_text("Two nodes, with a single child, each being reachable. The child is reachable, but is directly on the barrier.")


def negative_root_node_weight():
    filename = "negative_root_node_weight"

    test_case = (
        "5 10\n"
        "-100 90 100 110 120\n"
        "1 1 1 1"
    )
    Path(filename + ".in").write_text(test_case)
    Path(filename + ".desc").write_text("Root has negative weight and children are partially reachable.")


def binary_tree_two_layers():
    filename = "binary_tree_two_layers"

    test_case = (
        "7 10\n"
        "5 5 5 1 1 1 1\n"
        "1 1 3 3 2 2"
    )
    Path(filename + ".in").write_text(test_case)
    Path(filename + ".desc").write_text("Binary tree of 3 layers with unreachable third layer.")


def unreachable_subtree_with_negatives():
    filename = "unreachable_subtree_with_negatives"

    test_case = (
        "11 20\n"
        "1 3 7 -2 2 -6 1 30 3 5 5\n"
        "1 1 1 3 3 3 4 4 8 8"
    )
    Path(filename + ".in").write_text(test_case)
    Path(filename + ".desc").write_text("Unreachable subtree in a tree including negative weights.")


def exponential_weights():
    filename = "exponential_weights"

    test_case = (
        "14 15\n"
        "1 2 2 2 4 4 4 4 8 8 8 8 16 16\n"
        "1 1 1 3 3 4 4 6 6 8 8 10 10"
    )
    Path(filename + ".in").write_text(test_case)
    Path(filename + ".desc").write_text("Exponentially increasing weights of simple tree.")


def single_node_bottleneck():
    filename = "single_node_bottleneck"

    test_case = (
        "6 5\n"
        "1 10 -8 -8 -8 -8\n"
        "1 2 2 2 2"
    )
    Path(filename + ".in").write_text(test_case)
    Path(filename + ".desc").write_text("There is a single bottleneck in the tree, which renders all its children unreachable.")


def large_increasing_chain():
    test_case = ""

    employees = INPUT_LIMIT
    threshold = INPUT_LIMIT // 2
    test_case += f"{employees} {threshold}\n"

    levels = []
    for i in range(0, employees):
        levels.append(1)
    test_case += " ".join([str(x) for x in levels]) + "\n"

    bosses = []
    for i in range(1, employees):
        bosses.append(i)
    test_case += " ".join([str(x) for x in bosses])

    filename = "large_increasing_chain"
    Path(filename + ".in").write_text(test_case)
    Path(filename + ".desc").write_text("A long chain (only single child per node), where each child was weight 1.\nLimit Test.")


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

    filename = "switching_chain"
    Path(filename + ".in").write_text(test_case)
    Path(filename + ".desc").write_text("Long chain of nodes. Each node has either weight 1 or -1. No path length is larger 1.")


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

    filename = "negative_only"
    Path(filename + ".in").write_text(test_case)
    Path(filename + ".desc").write_text("In this tree, each nodes has three children. All weights are negative, which render no child unreachable.")


def random_test_case(case_number):
    test_case = ""

    employees = INPUT_LIMIT
    threshold = 5 * random.randint(1, 1_000)

    test_case += f"{employees} {threshold}\n"

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

    filename = f"random_test_case_{case_number}"
    Path(filename + ".in").write_text(test_case)
    Path(filename + ".desc").write_text(f"Randomly generated tree: test case #{case_number}; n={employees}, threshold={threshold}")


# ------------------------
# Small Test Cases
# ------------------------

# Relatively simple trees
binary_tree_two_layers()
unreachable_subtree_with_negatives()
exponential_weights()
single_node_bottleneck()
single_parent_single_child()
negative_root_node_weight()

# ------------------------
# Large Test Cases
# ------------------------

# Chain test cases: Tree, where each node has only one child
large_increasing_chain()
switching_chain()

# Each node has three children and each motivational level of -1
negative_only_test()

# Random test cases
for i in range(1, 4):
    random_test_case(i)