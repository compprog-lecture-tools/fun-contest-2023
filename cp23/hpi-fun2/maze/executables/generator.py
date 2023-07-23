import random
from pathlib import Path

random.seed(-6232152022358167641)

def createTest(name, maze):
  """
  name - name of the test that will be used for the created files

  maze - the maze represented as a string with " " and "#" for empty spaces and walls. The start has to be marked as "s" and the target as "t".

  Make sure there is exactly one start and one end in the maze.
  """
  count = 0
  wallString = ""
  start = None
  end = None

  lines = [line for line in maze.split("\n") if not len(line) == 0]
  height = len(lines)
  width = len(lines[0])
  for row, line in enumerate(lines, start = 0):
    for col, char in enumerate(line, start = 0):
      if (char == "\n" or char == " "): continue
      if (char == "s"):
        start = [col, row]
        continue
      if (char == "t"):
        end = [col, row]
        continue
      count += 1
      wallString += f"{col} {row}\n"
  if (not start or not end):
    print(f"ERROR creating test '{name}'. Didn't specify start or end.")
    return
  Path(f"{name}.desc").write_text(f"A maze with size {width}x{height} and {count} walls. The maze looks like this: {maze}")
  Path(f"{name}.in").write_text(f"""{width} {height} {count}
{start[0]} {start[1]}
{end[0]} {end[1]}
{wallString}""")

# Input:
# w h <walls>
# startX startY (beginning with 0)
# destX destY
# <walls> many lines containing coordinates x and y of the wall

createTest("sample", """
s 
# 
t 
""")

# TODO: Maybe we can create a random sample for the only judge that generates a random maze

createTest("sampleSmall", """
#######
# s   #
### ###
#   #t#
# ##  #
      #
  #####
""")

createTest("customMaze23x19", """
#######################
#s                    #
# ### ### ### ### ### #
# #                 # #
# # ##### ### ##### # #
# #                 # #
# ########### ####### #
# #                 # #
# ### ### ### ### #####
#   #                 #
##### ########### # # #
#   #                 #
# ############# # # # #
#             # # # # #
# ######### ### ### # #
# #t      # # # # # # #
# ####### # # # # ### #
#         #     #     #
#######################
""")

createTest("customMaze46x33", """
##############################################
#                #                         # #
### #### ### ######### ##### ### ######### # #
#   #      #  #     # #         #      #     #
# # # #### ### ### # # ### ##### # ####### ###
# # #  #     #   # # #   #   #   #  #       #
# # # ## ###### #### ##### # ### ## ####### #
#  s#  #  #  #   #   #   #   #      #       #
### ## # ## ## ####### ####### ########### #
# #    # # #  #     #   #   #           #   #
# ###### ### ## # ### # # # ### # ###### # #
# #          #  # #     #   # # #    # # # #
# #### ###### ## # ####### # # # #### # # #
#    #   #   #   # #     # # #      # #   #
### ## #### ###### ####### # ### ## ###### #
#   #    #   #    # #       #   # #    #    #
# # ### ## # ### ## # ####### ### # ###### #
# #     # # # #  #  #       #     # #      #
# ###### ### ## ###### ###### #### ## # ### #
#     #  #      #    #  #    #   #    #    #
# ### ####### ## ## #### #### ## # ######## #
# # #   #   #  #  #   #    # #  # #   #    #
# # ### # ### ### ## ## ## # ### ### # # ## #
# #     #    #      #  #           #     # #
# ###### ## ### ### ## ### ## #### #########
#          #   #    #   #    #              #
# # ####### #### ## ###### ### ## # ###### #
# #      #        #     #     #t  #    #   #
# ###### ## ##### ### ## ##  ## ## #### # #
#     #   #     #   #  #    #    #      #  #
# ###### ###### ### ## ## ###### ####### ##
#                         #                 #
##############################################
""")

longRowDimension = 50_000

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
{int(longRowDimension/2)} 0
{longRowDimension-1} 0                
""")
Path(f"longRowMiddleTargetRight.desc").write_text("Long row starting in the middle, target on the right.")

Path(f"longRowMiddleTargetLeft.in").write_text(f"""{longRowDimension} 1 0
{int(longRowDimension/2)} 0
0 0                
""")
Path(f"longRowMiddleTargetLeft.desc").write_text("Long row starting in the middle, target on the left.")

dimension = 200
halfPoint = int(dimension/2)

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