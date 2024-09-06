#include <bits/stdc++.h>
using namespace std;

void display(multiset<int> s)
{
  multiset<int>::iterator itr;
   
  // Displaying set elements
  for (itr = s.begin(); 
       itr != s.end(); itr++) 
  {
    cout << *itr << " ";
  }
  cout << "\n";
}  

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;

    cin >> n >> k;

    multiset<int> min;
    multiset<int> big;
    vector<int> v;

    int out = 0;

    while (n--) {
        int l;
        cin >> l;
        v.push_back(l);
    }

    /// first window
    vector<int> window;
    for (int i=0; i<k; i++) {
        window.push_back(v[i]);
    }
    sort(window.begin(), window.end());
    //first median
    int fmedian;
    if ((window.size()%2)!= 0) {
        fmedian = window[window.size()/2];
    }
    else {
        window[window.size()/2-1] < window[window.size()/2] ? 
        fmedian = window[window.size()/2-1]: fmedian = window[window.size()/2];  
    }
    cout << fmedian << " ";
    ///define sets
    for (int i=0; i<(k+1)/2; i++) {
        min.insert(window[i]);
    }
    for (int i=(k+1)/2; i<k; i++) {
        big.insert(window[i]);
    }

    // cout << "set\n";
    // display(big);
    // display(min);
    auto median = big.begin(); 
    for (int i=k; i< v.size(); i++) {

        //insert
        if (v[i] > *min.rbegin()) big.insert(v[i]);
        else min.insert(v[i]);  

        // cout <<"remove " << v[i-k] << "\n";
        if (v[i-k] > *min.rbegin()) big.erase(big.find(v[i-k]));
        else min.erase(min.find(v[i-k]));  
           
        //assure properties
        while (min.size() > (k+1)/2) {
            big.insert(*min.rbegin());
            min.erase(min.find(*min.rbegin()));
        }
        while (min.size() < (k+1)/2) {
            min.insert(*big.begin());
            big.erase(big.find(*big.begin()));            
        }
        //print median
        // cout << "set\n";
        // display(big);
        // display(min);
        cout << *min.rbegin() << " ";        
    }
        
    return 0;
}

