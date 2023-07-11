import random
from pathlib import Path

random.seed(-6232152022358167641)

# Input:
# w h <walls>
# startX startY (beginning with 0)
# destX destY
# <walls> many lines containing coordinates x and y of the wall

Path(f"sample.in").write_text("""2 3 1
0 0
0 2
0 1                          
""")
Path(f"sample.desc").write_text("small example")

# TODO: Maybe we can create a random sample for the only judge that generates a random maze

longRowDimension = 1_000_000

# Large row
Path(f"longRowStartLeft.in").write_text(f"""{longRowDimension} 1 0
0 0
{longRowDimension-1} 0                    
""")
Path(f"longRowStartLeft.desc").write_text("Long row starting left.")

Path(f"longRowStartRight.in").write_text(f"""{longRowDimension} 1 0
{longRowDimension-1} 0
0 0                
""")
Path(f"longRowStartRight.desc").write_text("Long row starting right.")

Path(f"longRowMiddleTargetRight.in").write_text(f"""{longRowDimension} 1 0
{longRowDimension/2} 0
{longRowDimension-1} 0                
""")
Path(f"longRowMiddleTargetRight.desc").write_text("Long row starting in the middle, target on the right.")

Path(f"longRowMiddleTargetLeft.in").write_text(f"""{longRowDimension} 1 0
{longRowDimension/2} 0
0 0                
""")
Path(f"longRowMiddleTargetLeft.desc").write_text("Long row starting in the middle, target on the left.")

dimension = 1_000
halfPoint = dimension/2

# Large open field
Path(f"largeField1.in").write_text(f"""{dimension} {dimension} 0
{halfPoint} {halfPoint}
0 0                       
""")
Path(f"largeField1.desc").write_text("Large open field without walls, target top left")

Path(f"largeField2.in").write_text(f"""{dimension} {dimension} 0
{halfPoint} {halfPoint}
{dimension-1} {dimension-1}                
""")
Path(f"largeField2.desc").write_text("Large open field without walls, target bottom right")

# Assuming an algorithm checking north -> east -> south -> west, this checks for the longest route
Path(f"longestRouteWest.in").write_text(
f"""{dimension} {dimension} 2
1 {halfPoint}
0 {halfPoint}
0 {halfPoint-1}
0 {halfPoint+1}
""")
Path(f"longestRouteWest.desc").write_text("Large open field with target directly west of start")

Path(f"longestRouteEast.in").write_text(
f"""{dimension} {dimension} 2
{dimension-2} {halfPoint}
{dimension-1} {halfPoint}
{dimension-1} {halfPoint-1}
{dimension-1} {halfPoint+1}
""")
Path(f"longestRouteEast.desc").write_text("Large open field with target directly east of start")

Path(f"longestRouteNorth.in").write_text(
f"""{dimension} {dimension} 2
{halfPoint} 1
{halfPoint} 0
{halfPoint-1} 0
{halfPoint+1} 0
""")
Path(f"longestRouteNorth.desc").write_text("Large open field with target directly north of start")

Path(f"longestRouteSouth.in").write_text(
f"""{dimension} {dimension} 2
{halfPoint} {dimension-2}
{halfPoint} {dimension-1}
{halfPoint-1} {dimension-1}
{halfPoint+1} {dimension-1}
""")
Path(f"longestRouteSouth.desc").write_text("Large open field with target directly south of start")