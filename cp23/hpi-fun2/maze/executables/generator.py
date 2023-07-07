import random
from pathlib import Path

random.seed(-6232152022358167641)

Path(f"sample.in").write_text("""3 3 4
0 0
0 2
2 0
0 1
2 1
2 2                           
""")
Path(f"sample.desc").write_text("small example")