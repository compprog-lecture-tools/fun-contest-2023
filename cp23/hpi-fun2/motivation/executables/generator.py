from pathlib import Path

SAMPLES = [
    [
        "sample1",
        """
          11 20
          2 5 3 7 2 1 10 4 1 8 2
          1 2 2 2 5 5 1 8 8 8
        """
    ],
    [
        "sample2",
        """
          5 7
          1 5 10 -2 -2
          1 1 3 3
        """
    ],
    [
        "sample3",
        """
          5 7
          8 5 10 -2 -2
          1 1 3 3
        """
    ]
]

for name, sample in SAMPLES:
    Path(name + ".in").write_text(sample + '\n')

def large_increasing_chain():
    sample = ""

    employees = 50_000
    threshold = 5_000
    sample += str(employees) + " " + str(threshold) + '\n'

    for i in range(0, employees):
        sample += str(1) + " "
    sample += '\n'

    for i in range(1, employees):
        sample += str(i) + " "
    sample += '\n'

    Path('large_increasing_chain.in').write_text(sample)


def large_switching_chain():
    sample = ""

    employees = 50_000
    threshold = 1
    sample += str(employees) + " " + str(threshold) + '\n'

    for i in range(0, employees):
        if i % 2 == 0:
            sample += str(1) + " "
        else:
            sample += str(-1) + " "

    sample += '\n'

    for i in range(1, employees):
        sample += str(i) + " "
    sample += '\n'

    Path('large_switching_chain.in').write_text(sample)


large_increasing_chain()
large_switching_chain()
