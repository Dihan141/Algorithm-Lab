#include<bits/stdc++.h>

using namespace std;

const int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int rows = 8;
const int cols = 8;

//Check if the given position is inside the chessboard
bool isValid(int x, int y) {
  return (x >= 0 && x < rows && y >= 0 && y < cols);
}

int BFS(char start_xC, int start_y, char end_xC, int end_y) {
    int start_x = start_xC - 'a';
    int end_x = end_xC - 'a';
    start_y--;
    end_y--;
    queue<pair<int, int>> q;
    bool visited[rows][cols];
    memset(visited, false, sizeof(visited));

    q.push(make_pair(start_x, start_y));
    visited[start_x][start_y] = true;

    int distance[8][8];
    memset(distance, 0, sizeof(distance));

    while (!q.empty()) {
      pair<int, int> curr = q.front();
      q.pop();

      if (curr.first == end_x && curr.second == end_y) {
        return distance[end_x][end_y];
      }

      for (int i = 0; i < 8; i++) {
        int new_x = curr.first + dx[i];
        int new_y = curr.second + dy[i];

        if (isValid(new_x, new_y) && !visited[new_x][new_y]) {
          q.push(make_pair(new_x, new_y));
          visited[new_x][new_y] = true;
          distance[new_x][new_y] = distance[curr.first][curr.second] + 1;
        }
      }
    }
    return -1;
}

int main() 
{
    char startC, destC;
    int startI, destI;
    cin>>startC>>startI;
    cin>>destC>>destI;

    int moves = BFS(startC, startI, destC, destI);
    cout<<"To get from "<<startC<<startI<<" to "<<destC<<destI<<" takes "<<moves<<" knight moves."<<endl;
    return 0;
}
