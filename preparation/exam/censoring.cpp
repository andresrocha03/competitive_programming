#include <bits/stdc++.h>
using namespace std;

const size_t G = 1e6+3;
const size_t P = 18446744073709551533ULL;


size_t h(size_t r, char c) {
    __uint128_t a = r;
    a *= G;
    a += c;
    return (a%P);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    //build hash of t
    int len_t = t.size();
    size_t hash_t = 0;
    size_t remove = 1;
    for (char c:t) {
        hash_t = h(hash_t, c);
        remove = h(remove, 0);
    }

    vector<char> out;
    vector<size_t> hs = {0};
    for (int i=0;i<(int)s.size();i++) {
        
        //add hashing of window of length t, including current char
        hs.push_back(h(hs.back(),s[i]));
        out.push_back(s[i]);
        if (out.size() > len_t) {
            __uint128_t sub =
            (__uint128_t)remove * (unsigned char)out[out.size() - 1 - len_t];

            sub %= P;

            hs.back() = (size_t)(((__uint128_t)hs.back() + P - sub) % P);
        }   
        //check if the last len_t characters match t
        if (hs.back() == hash_t) {
            for (int j=0;j<len_t;j++) {
                out.pop_back();
                hs.pop_back();
            }
        }
    }

    for (char c:out) {
        cout << c;
    }
    cout << "\n";

    return 0;
}