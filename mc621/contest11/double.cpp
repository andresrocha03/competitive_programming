#include <bits/stdc++.h>
using namespace std;


int main()  {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        char v[100001][9];
        char str[9];
        set<string> s;
        int i = 0;
        int aux = n;
        while (aux--) {
            cin >> str;
            s.insert(str);
            memcpy(v[i], str, strlen(str)+1);
            i++;
        }
        for (int i=0; i<n;i++) {
            int tam2 = strlen(v[i]);
            int found =0;
            // for () {
                for (int j=1;j<tam2; j++) {
                    char esq[9];
                    strncpy(esq,v[i],j);
                    esq[j] = '\0';
                    char dir[9];
                    strncpy(dir,v[i]+j, tam2-j);
                    dir[tam2-j] = '\0';
                    // cout << "esq " << esq << "\n";
                    // cout << "dir " << dir << "\n";
                    if (s.find(esq) != s.end() && s.find(dir)!= s.end()) {
                        cout << 1;
                        found = 1;
                        break;
                    }
                }
                if (!found) cout << 0;
                
            // }
            
        }
        cout << "\n";


    }


    return 0;
}