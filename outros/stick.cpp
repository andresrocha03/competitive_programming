#include <bits/stdc++.h>

using namespace std;


// Function to find the maximum element 
int findMax(set<int> my_set) 
{ 
 
    // Get the maximum element 
    int max_element; 
    if (!my_set.empty()) 
        max_element = *(my_set.rbegin()); 
 
    // return the maximum element 
    return max_element; 
} 

int findMin(set<int> my_set) 
{ 
    // Get the minimum element 
    int min_element; 
    if (!my_set.empty()) 
        min_element = *my_set.begin(); 
 
    // return the minimum element 
    return min_element; 
} 

bool flag = 0;
int  cont;
bool finish = 0;
int FindSubsetSum(vector<int> l,X)
{

// Loop para encontrar um subconjunto cuja soma dos elementos seja igual a X
    for (int i = 0; i < (1 << l.size()); i++) { // para cada subconjunto, O(2^n)
    int sum = 0;
    for (int j = 0; j < l.size(); j++) { // verificação de pertinência, O(n)
        if (i & (1 << j)) { // teste se o bit 'j' está ligado no subconjunto 'i'
            sum += l[j]; // se sim, processa 'j'
        }
    }
    if (sum == X) {
        
        break; // a resposta é encontrada: máscara de bits 'i'
    }

}

}
 

void solve(set<int> s, vector<int> set) {
        int m,value,max,sum;
        vector<int> aux;

        cin >> m;
        for (int i=0; i<s.size()/4+1; i++) {
            max = findMax(s);
            s.erase(max);
            aux.push_back(max);
        }

        for (int i=0;i<aux.size();i++) {
            sum += aux[i];
        }
        
        for (int i=0;i<aux.size();i++) {
            s.insert(aux[i]);
        }


        vector<int> subset;
        for (int i=findMin(s);i<sum;i++) {
            flag = 0;
            finish = 0;
            cont = 0;
            if (FindSubsetSum(0, set.size(), set, i, subset)) {
                cout << "yes\n";
            }
            else {
                cout << "no\n";
            }
        }


    } 






int main() {    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m,value, max, min;
    vector<int> v;
    set<int> s;

    cin >> n;

   // min = findMin(s);

    for (int i =0; i<n ; i++) { 
        cin >> m;
        for (int i =0; i<m ; i++) {
            cin >> value;
            s.insert(value);
            v.push_back(value);
        }
        solve(s,v);
    }

}