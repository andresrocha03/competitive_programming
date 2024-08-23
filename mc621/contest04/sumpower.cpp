#include <bits/stdc++.h>
#include <math.h>
using namespace std;

//o código abaixo foi retirado dos slides disponíveis no moodle
#define MAXDIGITS 100 /* maximum length bignum */
#define PLUS 1 /* positive sign bit */
#define MINUS -1 /* negative sign bit */

typedef long long ll;
typedef struct {
    char digits[MAXDIGITS]; /* represent the number */
    int signbit; /* 1 if positive, -1 if negative */
    int lastdigit; /* index of high-order digit */
} bignum;

void ll_to_bignum(ll s, bignum *n) {
    int i; /* counter */
    ll t; /* auxiliary */

    if (s >= 0) n->signbit = PLUS;
    else n->signbit = MINUS;

    for (i = 0; i < MAXDIGITS; i++) n->digits[i] = (char) 0;
    n->lastdigit = -1;

    // absolute value
    t = (s >= 0) ? s : -s;
    while (t > 0) {
        n->lastdigit++;
        n->digits[n->lastdigit] = (char) (t % 10);
        t = t / 10;
    }

    if (s == 0) n->lastdigit = 0;
}

//o código acima foi retirado dos slides disponíveis no moodle

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a,n,m, res=0;
    unsigned long long pow=1;

    cin >> a >> m >> n;
    
    bignum big, pow;
    ll_to_bignum(a,&big);

    for (int i=0; i<n; i++) {
        pow = 1;
        for (int j=0; j<i; j++) {
            pow *= a%m;
            pow %= m;
        }
        res += pow;
        res %= pow;
    }

    return 0;
}