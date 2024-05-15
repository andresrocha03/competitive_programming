#include <bits/stdc++.h>

using namespace std;

int giveanswer(int n) {
    int answer=0;
    vector<int> v;

    if (n==1) {
        return 1; 
    }
    else if (n==2) {
        return 1;
    }
    else if (n==3) {
        return 2;
    }
    else if (n==4) {
        return 2;
    }
    else if (n%2 != 0) {
        return n/2 +1;
    }
    return n/2;

    //for (int i=1; i<=n; i++) {
     //   v.push_back(i);
    //}

   // for (int i=0; i<v.size(); i++) {
    //    for (int j=0; j<v.size(); j++) {

    //    }
    //}

    //return answer;
}






int main() {    
    ios::sync_with_stdio(false);
    cin.tie(0);
    int qtd,n;
    cin >> qtd;
    for (int i=0; i<qtd; i++) {
        cin >> n;
        cout << giveanswer(n) << "\n";
    }
    return 0;
}