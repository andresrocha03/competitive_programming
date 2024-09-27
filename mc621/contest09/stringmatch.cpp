#include <bits/stdc++.h>
using namespace std;

//essa funcao foi retirada dos slides
// Function to compute the LPS array
void computeLPSArray(string P, int M, int* lps) {
    int len = 0;
    lps[0] = 0; // lps[0] is always 0
    int i = 1;

    // Calculate lps[i] for i = 1 to M-1
    while (i < M) {
        if (P[i] == P[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int res=0;
//essa funcao foi retirada dos slides
// Prints occurrences of pattern P in text T
void KMPSearch(string P, string T) {
    int M = P.size();
    int N = T.size();
    
    // Create lps[] that will hold the longest prefix suffix values for pattern
    int lps[M];
    
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(P, M, lps);
 
    int i = 0; // index for T
    int j = 0; // index for P

   
    while (i < N) {
        if (P[j] == T[i]) {
            j++;
            i++;
        }

        if (j == M) {
            res++;
            j = lps[j - 1];
        }
        // mismatch after j matches
        else if (i < N && P[j] != T[i]) {
            // Do not match lps[0..lps[j-1]] characters
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string p, t;

    cin >> t >> p;
    KMPSearch(p,t);
    cout << res << "\n";


    return 0;
}