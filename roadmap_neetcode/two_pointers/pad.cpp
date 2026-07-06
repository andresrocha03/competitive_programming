#include <bits/stdc++.h>
using namespace std;



bool isPalindrome(string S) {
    //normalize string to lower case and remove non-alphanumeric characters
    string clean = "";
    cout << S << "\n";
    for (int i=0;i<S.size();i++) {
        if (isalnum(S[i])) {
            clean+=tolower(S[i]); 
        }
    }

    bool res=true;
    int j=clean.size()-1;
    for (int i=0;i<clean.size();i++) {
        if ((clean[i]!=clean[j])) 
            return false;
        j--;
    }
    return true;
}

int main( ) {
    string S; 
    getline(cin, S);

    if (isPalindrome(S)) cout << "true\n";
    else cout << "false\n";

    return 0;
}