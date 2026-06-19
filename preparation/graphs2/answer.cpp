#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int Nm = 500 ; // max dimension of the grid
const int Km = 10000 ; // max number of asteroids
const int Tm = Nm*2+2; // max number of nodes : 2×dimension (#rows + #cols) + 2 (source and target nodes)

int capa[Tm][Tm], flow[Tm][Tm], N, K ;
bool visited[Tm];

bool dfs(int x) {
  if(visited[x])
    return false ;
  if(x==Tm-1)
    return true;
  visited[x] = true;
  for(int j = 0 ; j < Tm ; j++)
    if(flow[x][j] < capa[x][j])
      if(dfs(j)) {
        flow[x][j]++;
        flow[j][x]--;
        return true;
      }
  return false;        
}

int main () {
  scanf("%d %d\n",&N, &K);
  for(int i = 0 ; i < Nm ; i++) // for each col
    capa[Tm-2][i] = 1 ; // Tm-2 is source node we add (source->cols) edges
  for(int i = 0 ; i < Nm ; i++) // for each row
    capa[i+Nm][Tm-1] = 1 ; // Tm-1 is target node we add (row->target) edges

  for(int i = 0 ; i < K ; i++) {
    int f,t ;
    scanf("%d %d\n",&f,&t);
    capa[f][Nm+t]=1; // set capacity for edge of asteroid
  }
  int res = 0 ;
  while(dfs(Tm-2)) { // repeat dfs from source node
    res++;
    fill(visited,visited+Tm,false); // reset visited for next dfs, flow increases by one each time
  }
  printf("%d\n",res);
  return 0;
}