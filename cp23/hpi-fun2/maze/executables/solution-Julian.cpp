#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<bool>> visited;

bool visit(int x, int y, char backtracking) {
  visited[y][x] = true;
  string input;
  cin >> input;
  if (input == "EXIT") return true;
  for (int i = 0; i < 4; i++) {
    char field = input[i];
    if (field == '#') continue;
    int target_x = x;
    int target_y = y;
    char direction;
    char back_direction;
    switch (i)
    {
    case 0:
      target_y--;
      direction = 'N';
      back_direction = 'S';
      break;
    case 1:
      target_x++;
      direction = 'E';
      back_direction = 'W';
      break;
    case 2:
      target_y++;
      direction = 'S';
      back_direction = 'N';
      break;
    case 3:
      target_x--;
      direction = 'W';
      back_direction = 'E';
      break;
    }
    if (direction == backtracking) continue; // Dont go back here
    if (visited[target_y][target_x]) continue; // We have been there before, dont need to check again
    cout << direction << endl;
    if (visit(target_x, target_y, back_direction)) return true;
  }
  cout << backtracking << endl;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int w, h;
  cin >> w >> h;

  visited = vector<vector<bool>>(2 * (h + 1), vector<bool>(2 * (w + 1), false));
  visit(w + 1, h + 1, ' ');

  return 0;
}