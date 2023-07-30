#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

#define WALL '#'
#define FREE '_'

void send_neighbor_info(int x, int y, vector<vector<bool>>& maze) {
  char up = (y == 0 || maze[y - 1][x]) ? WALL : FREE;
  char down = (y == maze.size() - 1 || maze[y + 1][x]) ? WALL : FREE;

  char left = (x == 0 || maze[y][x - 1]) ? WALL : FREE;
  char right = (x == maze.front().size() - 1 || maze[y][x + 1]) ? WALL : FREE;

  cout << up  << right << down << left << endl;
}

bool is_valid_move(int x, int y, int width, int height, vector<vector<bool>>& maze) {
  return x >= 0 && x < width && y >= 0 && y < height && !maze[y][x];
}

int main(int argc, char* argv[]) {
  setName("describe your interactor here");
  registerInteraction(argc, argv);

  // Use inf (.in file) and ans (.ans file).
  // Read queries from the solution using ouf, and write to it using cout.
  // Use quit(_wa, message) or quitf(_wa, format_string, args...) to report wrong answers
  // Exchange _wa by _pe if the format is wrong (should mostly be taken care of by the
  // input functions of ouf).
  // Remember that you should probably have a query limit and enforce it.

  const auto width = inf.readInt();
  const auto height = inf.readInt();
  const auto walls = inf.readUnsignedLong();

  auto maze = vector<vector<bool>>(height, vector<bool>(width, false));

  auto x = inf.readInt();
  auto y = inf.readInt();

  const auto end_x = inf.readInt();
  const auto end_y = inf.readInt();

  for (auto i = uint64_t{0}; i < walls; ++i) {
    const auto x = inf.readInt();
    const auto y = inf.readInt();
    maze[y][x] = true;
  }

  auto fail_move = [&](char move_direction) {
    cout << -1 << endl;
    string msg = "invalid move: Trying to move '" + string(1, move_direction) + "' with x: " + to_string(x) + " and y: " + to_string(y);
    quit(_wa, msg);
  };

  auto fail_input = []() {
    cout << -1 << endl;
    quit(_wa, "invalid input");
  };

  const auto max_queries = uint64_t{5} * width * height;
  cout << width << " " << height << endl;
  for (int queriesRemaining = max_queries; queriesRemaining >= 0; --queriesRemaining) {
    send_neighbor_info(x, y, maze);
    char move_direction = ouf.readToken("N|E|S|W").front();
    switch (move_direction) {
      case 'N':
        if (is_valid_move(x, y - 1, width, height, maze)) {
          --y;
        } else {
          fail_move(move_direction);
        }
        break;
      case 'E':
        if (is_valid_move(x + 1, y, width, height, maze)) {
          ++x;
        } else {
          fail_move(move_direction);
        }
        break;
      case 'S':
        if (is_valid_move(x, y + 1, width, height, maze)) {
          ++y;
        } else {
          fail_move(move_direction);
        }
        break;
      case 'W':
        if (is_valid_move(x - 1, y, width, height, maze)) {
          --x;
        } else {
          fail_move(move_direction);
        }
        break;
      default:
        fail_input();
    }

    if (x == end_x && y == end_y) {
      cout << "EXIT" << endl;
      quit(_ok, "you have reached the exit");
    }
  }
  cout << -1 << endl;
  quit(_wa, "too many queries");
}
