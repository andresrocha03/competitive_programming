#include <bits/stdc++.h>

using namespace std;

int main() {    
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector <set<char>> v; 
    vector <char> vertices;
    string aresta="000",lista;
    int find=0,n,sets=0,acorn=0;
    char v1,v2;
    cin >> n;
    for (int i=0; i<n; i++) {
         while (aresta[0] != '*') {
            cin >> aresta;
            v1 = aresta[1];
            v2 = aresta[3];
            for (int j=0; j<v.size(); j++) {
                if (v[j].find(v1) != v[j].end()) {
                    find = 1;
                    v[j].insert(v2);
                    vertices.push_back(v2);
                    break;
                }
            }
            if (find == 0) {
                v[sets].insert(v1);
                v[sets].insert(v2);
                vertices.push_back(v1);
                vertices.push_back(v2);
                sets++;
            }
            find = 0;
        }
    }
    cin >> lista;
    for (auto &x : lista) {
        for (int j=0; j<v.size(); j++) {
            if (v[j].find(x) == v[j].end()) { 
                find =1;
                break;
            }
        }
        if (find ==0) {
            acorn++;
        }
        find =0;
    }
    v.clear();
    cout << "There are" << v.size() << "trees and" << acorn << "acorn(s).";
    } 


