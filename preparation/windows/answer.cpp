#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int Tm = 1e5 + 10 ;
long long spice[Tm], flavor[Tm], N, M;

int main () {
  scanf("%lld %lld",&N,&M);
  for(int i = 0 ; i < N ; i++)
    scanf("%lld %lld",flavor+i,spice+i);
  
  long long start=0, cur_flavor=0, best_spiciness=1e9+10;
  multiset<long long> spiciness ; // multiset is important here! We can have duplicate spiciness
  
  for(int end=0 ; end < N ; end++ ) { // we do a sliding window 
    cur_flavor += flavor[end]; // add a new haybale
    spiciness.insert(spice[end]); // add its spiciness
    
    while(cur_flavor-flavor[start]>=M) { // remove haybales while remaining above the target flavor
      cur_flavor-=flavor[start];
      spiciness.extract(spice[start]);
      start++;
    }
    
    if(cur_flavor>=M) // double check that we have enough flavor (might not be the case at the begginging)
      best_spiciness=min(best_spiciness,*spiciness.rbegin());
  }
  printf("%lld\n",best_spiciness);
}