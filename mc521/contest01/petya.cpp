#include <iostream>
using namespace std;

int main()
{    
    std::string s1, s2;
    cin >> s1;
    cin >> s2;
    
    for (auto& x : s1) { 
        x = tolower(x); 
    } 
    for (auto& x : s2) { 
        x = tolower(x); 
    }

    if (s1<s2) {
        cout << -1; 
    }
    else if (s1.compare(s2)==0) {
        cout << 0;
    }
    else if (s1>s2){
        cout << 1;
    };

}