#include <iostream> 
using namespace std; 
#include <vector>

int get_answer(vector<int> v) {
    int change = 0;
    int answer = 0;
    for (int i=0; i< v.size()-1; i++) {
        if ((v[i] > v[i+1]) && change==0) {
            change = 1;
            answer++;
        }
        else change = 0;
    }
    return answer;
}




int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tests, n, x, aux, answer;
    vector<int> vec;

    cin >> tests;

    for (int i=0; i<tests; i++) {
        cin >> n;
        for (int j=0; j<n; j++) {
            cin >> x;
            vec.push_back(x);
        }
        cout << get_answer(vec);
        cout << "\n";
        vec.clear();

    }
    return 0 ;
}