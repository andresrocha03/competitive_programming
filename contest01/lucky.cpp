#include <bits/stdc++.h>

using namespace std;

int main() {    
    ios::sync_with_stdio(false);
    cin.tie(0);
    std::string s1, lucky;
    int four=0,seven=0,find=0;

   cin >> s1;
    
    for (auto& x : s1) { 
        if (x == '4') {
            four++;  
            find = 1;      
        } 
        else if (x == '7') {
            seven++;
            find =1;
        }
        else {
            find = 0;
        }
    } 
    if (four==0 && seven==0) {
        cout << -1;
    }
    else {
        if (four>seven) {
            cout << "4";
        }
        else if (four==seven){
            cout << "4";
        }
        else if (seven>four) {
            cout << "7";
        }
    }
    return 0;
}