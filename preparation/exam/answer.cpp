#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int Tm = 1e5 + 10 ;
vector<int> nxt[Tm];
int nb_potions[Tm],n,a,b, potion[Tm];

// val(node,parent) returns a pair: number of leaves and number
// potions that can be gained on the subtree rooted in cur
// (i.e. excluding parent)
pair<int,int> val(int cur, int parent) {
  int nb_tra = 0, nb_pot = 0;
  
  for(int c : nxt[cur]) 
    if(c != parent) { // explore all children (not the parent)
      pair<int,int> sub = val(c,cur);
      nb_tra += sub.first; // total nb of leaves
      const int add = min(nb_potions[cur],sub.first-sub.second);
      // we can add $add potions from the current node if there are
      // leaves explored where we haven't gained potions
      nb_potions[cur]-= add;
      nb_pot += add+sub.second;
      }
  
  if(nb_tra == 0) { // we are a leaf
    nb_tra = 1;
    nb_pot = min(1,nb_potions[cur]);
  }
  return {nb_tra,nb_pot};
}

int main () {
  scanf("%d",&n);
  if(n==1) {
    printf("1\n");
    return 0;
  }
  for(int i = 0 ; i < n ; i++) 
    scanf("%d",potion+i);
  for(int i = 0 ; i+1 < n ; i++) {
    scanf("%d %d",&a,&b);
    nxt[a].push_back(b);
    nxt[b].push_back(a);
  }

  int nb_traversals = 0;
  for(int i = 2 ; i <= n ;i++)
    if(nxt[i].size()==1)
      nb_potions[potion[nb_traversals++]]++;
  printf("%d\n",val(1,0).second);
}