#include <bits/stdc++.h>
using namespace std;

//extraído de https://cp-algorithms.com/string/manacher.html
vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string t) {
    string s;
    for(auto c: t) {
        s += string("#") + c;
    }
    auto res = manacher_odd(s + "#");
    return vector<int>(begin(res) + 1, end(res) - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    int option = 0;
    string t;
    while (cin>>t) {
        //verificar se já é um palíndromo
        int r = t.size()-1, l = 0;
        int pal = 0;
        while (t[l]==t[r]) {
            l++;
            r--;
            if (l>r) {
                cout << t << "\n";
                pal++;
                break;
            }
        }
        if (!pal) {
            vector<int> res = manacher(t);
            //cout << t << "\n";
            // for (int i=0; i<res.size();i++) {
            //     cout << "i: " << i << " " <<res[i] << "\n";
            // }
            int i;
            int soma =0;
            for (i=t.size()/2; i<t.size(); i++) {
                if ((i + (res[2*i-1])/2) == t.size()) {
                    soma--;
                    break;
                } 
                else if ((i + (res[(2*i)])/2) == t.size() ) {
                    //soma+=2;
                    break;
                };
            }
            // cout << i;
            cout << t;
            for (int j=i-((res[2*i+soma]/2)-soma); j>=0; j--) {
                cout << t[j];
            }
            cout << "\n";
            // cout << "soma" << soma << "\n";
        }
    }
    return 0;
}