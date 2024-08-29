#include <bits/stdc++.h>

using namespace std;

int main() {    
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> possible = {2,7,2,3,3,4,2,5,1,2};
    string number;
    
    cin >> number;
    cout << possible[int(number[0])-48] * possible[int(number[1])-48]; 

}