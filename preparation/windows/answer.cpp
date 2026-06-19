#include <cstdio>

char S[3001], T[3000001]  ;
int lenS, lenT ; 

int nbZ = 256 ;
int diff[ 256 ] ; // diff number in patterns - number in current window

void change(int chr, int dir) {
  if(diff[chr] == 0)
    nbZ -- ;
  diff[chr] += dir ;
  if(diff[chr] == 0)
    nbZ ++ ;
}

int main () {
  scanf("%d %d\n%s\n%s\n",&lenS, &lenT,S,T);
  for(int pos = 0 ; pos < lenS ; pos++) {
    change(S[pos], +1) ;
    change(T[pos], -1) ;
  }
  int res = 0 ;
  for(int pos = lenS ; pos <= lenT ; pos++ ) {
    if(nbZ == 256)
      res++;
    change(T[pos],-1) ;
    change(T[pos-lenS],+1) ;
  }
  printf("%d\n",res);
  return 0 ;}