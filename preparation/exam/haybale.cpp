#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll oo = 1e18;

int main () {

    ll n,m; cin >> n >> m;
    vector<ll> fs(n), ss(n);
    
    for(int i = 0 ; i < n ; i++)
        cin >> fs[i] >> ss[i];

    ll st=0, cur_flavor=0, best_spiciness=oo;
    multiset<ll> spiciness ; 

    for(int e=0 ; e < n ; e++ ) {  
        cur_flavor += fs[e]; 
        spiciness.insert(ss[e]); 


        if(cur_flavor>=m)  {
            best_spiciness=min(best_spiciness,*spiciness.rbegin());
            while(cur_flavor>=m) { 
                cur_flavor-=fs[st];
                spiciness.extract(ss[st]);
                st++;
            }
        }
    }
    cout << best_spiciness << endl;
}