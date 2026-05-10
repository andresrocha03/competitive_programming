#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    int low=50;
    int high=-50;

    while (getline(cin, s)) {
        //throw out 11 first char
       
        for (int i=11; i<s.size();i++) { //iterate line
            int sign =1;
            if (s[i] == '-') {
                sign = -1;
                i++;
            }
            int num = 0;
            int exp = 0;
            while (i<s.size() && s[i] != ' ') { //iterate number
                num = num*10 + (s[i] - '0');
                i++;
                exp++;
            }
            num *= sign;
            high = max(high,num);
            low = min(low,num);
                       
        }
    }

    cout << low << " " << high << "\n";

    return 0;
}