#include <iostream>
#include <queue>

using namespace std;

int N, M;
int map[50][50];
int space = 0;
int space_cnt = 1;
pair<int, int> dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
queue<pair<int, int>> q;

bool isPossible(int y, int x) {
     if ( y >= 0 && x >= 0 && y < N && x < M )
          return true;
     return false;
}
void dfs(int y, int x, int d) {
     if ( space_cnt == space){
          return ;
     }
     for(int i=3; i >= 0; i--) {
          int nextD = (d+i)%4;
          int nextY = y + dir[nextD].first;
          int nextX = x + dir[nextD].second;
          if ( isPossible(nextY, nextX) ) {
               if ( map[nextY][nextX] == 0) {
                    map[nextY][nextX] = 2;
                    space_cnt++;
                    dfs(nextY,nextX,nextD);
                    return;
               }
          }
     } 
     int preY = y + dir[d].first * (-1);
     int preX = x + dir[d].second * (-1);
     if ( isPossible(preY, preX)) {
          if (map[preY][preX] == 2) {
               dfs(preY,preX,d);
          }
     }
     return;
}

int main()
{
     int r, c, d;
     cin >> N >> M >> r >> c >> d;
     
     for (int i = 0; i < N; i++)
     {
          for (int j = 0; j < M; j++)
          {
               cin >> map[i][j];
               if ( map[i][j] == 0 )
                    space++;
          }
     }
     map[r][c] = 2;
     dfs(r,c,d);

     cout << space_cnt << endl;
     return 0;
}


