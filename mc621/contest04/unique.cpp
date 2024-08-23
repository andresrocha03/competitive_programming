#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    long long res=1;
    long long i=0,j=1;
    set<char> letters;

    while (true){
        if (s[i] != s[j]) {
            if ((letters.find(s[i]) != letters.end()) || ((letters.find(s[j]) != letters.end()))) {
                i++;
                res++;
                j = i + 1;
            }
            else {
                res++;
                j++;
                letters.insert(s[i]);
                letters.insert(s[j]);
            } 
        }
        else if  (s[j]==s[i]) {
            i++;
            res++;
            j = i + 1;
        }
        if (j==s.size()) {
            i++;
            res++;
            j = i + 1;
            if (j==s.size()) {
                break;
            }
        } 
        if (i==s.size())    break;
    }
    cout << res << "\n";
}

// aba
// a -> 1 
// ab -> 2
// abb -> 