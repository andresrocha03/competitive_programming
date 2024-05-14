#include <bits/stdc++.h>
using namespace std;


int seq(int n) {
    int res[n+1];
    res[0] =0;
    res[1] =0;
    res[2] = 2;
    res[3] = 3;

    for (int i=4; i<=n; i++) {
        res[i] = (res[i-1] + res[i-2])%((int)pow(10,9)+7);
    } 
    return res[n];
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    int answer=1, len=0, possible=1, i=0;
    vector<int> npos, upos;
   
    cin >> str;

    for (auto &c:str) {    
        if (c=='u') {
            upos.push_back(1);
            npos.push_back(0);
        }
        else if (c=='n') {           
            npos.push_back(1);
            upos.push_back(0);
        }
        else {
            if (c=='m' || c=='w') {
                possible = 0;
                break;
            }
            upos.push_back(0);
            npos.push_back(0);
        }
    }

    if (possible) {
        while ( i< upos.size()) {
            if (upos[i]==1 && upos[i+1]==1) {
               len =0;
               while (upos[i]==1) {
                    len++;
                    i++;
               } 
               answer = ((answer%((int)pow(10,9)+7))*(seq(len)%((int)pow(10,9)+7)))%((int)pow(10,9)+7);
            }
            else i++;
        }
        i=0;
        while (i < npos.size()) {
            if (npos[i]==1 && npos[i+1]==1) {
               len = 0;
               while (npos[i]==1) {
                    len++;
                    i++;
               } 
               answer = ((answer%((int)pow(10,9)+7))*(seq(len)%((int)pow(10,9)+7))%((int)pow(10,9)+7));
            }
            else i++;
        }
    }
    else answer =0;
    
    cout << answer;
}