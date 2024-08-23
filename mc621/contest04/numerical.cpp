#include <bits/stdc++.h>
using namespace std;


//código abaixo retirado dos slides da matéria e adaptado ao problema
#define MAXDIGITS 2010 /* maximum length bignum */
#define PLUS 1 /* positive sign bit */
#define MINUS -1 /* negative sign bit */

typedef long long ll;
typedef struct {
    char digits[MAXDIGITS]; /* represent the number */
    int signbit; /* 1 if positive, -1 if negative */
    int lastdigit; /* index of high-order digit */
} bignum;

void add_bignum(bignum *a, bignum *b, bignum *c);
void subtract_bignum(bignum *a, bignum *b, bignum *c);
int compare_bignum(bignum *a, bignum *b);

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


void str_to_bignum(string s, bignum *n) {
    int i; /* counter */
    ll t; /* auxiliary */

    n->signbit = PLUS;
for (i = 0; i < MAXDIGITS; i++) n->digits[i] = (char) 0;
    int index = s.size() - 1;
    for (i = 0; i < s.size(); i++) {
        n->digits[i] = s[index]-'0';
        index--;
    }
    n->lastdigit = s.size()-1;
}

void initialize_bignum(bignum *num){
    for (int i = 0; i < MAXDIGITS; i++) num->digits[i] = (char) 0;
    num->lastdigit=0;
    num->signbit=PLUS;
}

void digit_shift(bignum *n, int d) { /* multiply n by 10^d */
    int i; /* counter */

    if ((n->lastdigit == 0) && (n->digits[0] == 0)) return;

    for (i = n->lastdigit; i >= 0; i--)
        n->digits[i + d] = n->digits[i];

    for (i = 0; i < d; i++) n->digits[i] = 0;

    n->lastdigit = n->lastdigit + d;
}

void zero_justify(bignum *n) {
    while ((n->lastdigit > 0) && (n->digits[n->lastdigit] == 0))
        n->lastdigit--;

    if ((n->lastdigit == 0) && (n->digits[0] == 0))
        n->signbit = PLUS; /* hack to avoid -0 */
}

void subtract_bignum(bignum *a, bignum *b, bignum *c) {
    int borrow; /* has anything been borrowed? */
    int v; /* placeholder digit */
    int i; /* counter */

    initialize_bignum(c);

    // if a number is negative, invert its sign and sum.
    if ((a->signbit == MINUS) || (b->signbit == MINUS)) {
        b->signbit = -1 * b->signbit;
        add_bignum(a, b, c);
        b->signbit = -1 * b->signbit;
        return;
    }

    // place as first bignum the largest one (in magnitude)
    if (compare_bignum(a, b) == PLUS) {
        subtract_bignum(b, a, c);
        c->signbit = MINUS;
        return;
    }

    c->lastdigit = std::max(a->lastdigit, b->lastdigit);
    borrow = 0;

    // subtract the number implementing the borrowing system.
    for (i = 0; i <= (c->lastdigit); i++) {
        v = (a->digits[i] - borrow - b->digits[i]);
        if (a->digits[i] > 0) borrow = 0;
        if (v < 0) {
            v = v + 10;
            borrow = 1;
        }
        c->digits[i] = (char) v;
    }
    zero_justify(c);
}
void add_bignum(bignum *a, bignum *b, bignum *c) {
    int i, carry; /* carry digit */
    initialize_bignum(c);

    if (a->signbit == b->signbit) c->signbit = a->signbit;
    else {
        if (a->signbit == MINUS) {
            a->signbit = PLUS;
            subtract_bignum(b, a, c);
            a->signbit = MINUS;
        } else {
            b->signbit = PLUS;
            subtract_bignum(a, b, c);
            b->signbit = MINUS;
        }
        return;
    }

    c->lastdigit = std::max(a->lastdigit, b->lastdigit) + 1;
    carry = 0;

    for (i = 0; i <= (c->lastdigit); i++) {
        c->digits[i] = (char) (carry + a->digits[i] + b->digits[i]) % 10;
        carry = (carry + a->digits[i] + b->digits[i]) / 10;
    }
    zero_justify(c);
}

int compare_bignum(bignum *a, bignum *b) {
    int i; /* counter */

    if ((a->signbit == MINUS) && (b->signbit == PLUS)) return (PLUS);
    if ((a->signbit == PLUS) && (b->signbit == MINUS)) return (MINUS);

    if (a->lastdigit > b->lastdigit) return (MINUS * a->signbit);
    if (b->lastdigit > a->lastdigit) return (PLUS * a->signbit);

    for (i = a->lastdigit; i >= 0; i--) {
        if (a->digits[i] > b->digits[i]) return (MINUS * a->signbit);
        if (b->digits[i] > a->digits[i]) return (PLUS * a->signbit);
    }

    return 0;
}


void print_bignum(bignum *rest) {
    for (int i=rest->lastdigit; i>=0;i--) {
        cout << (char) (rest->digits[i] + '0');
    }
    cout << "\n";
}


void divide_bignum(bignum *a, bignum *b, bignum *c, bignum *r) {
    bignum row; /* represents shifted row */
    bignum tmp; /* placeholder bignum */
    int asign, bsign; /* temporary signs */
    int i, j; /* counters */
    // cout << "before"<<endl;
    initialize_bignum(c);
    initialize_bignum(&row);
    initialize_bignum(&tmp);

    // cout << "intialized"<<endl;
    c->lastdigit = a->lastdigit;
    c->signbit = a->signbit * b->signbit;
    asign = a->signbit; a->signbit = PLUS;
    bsign = b->signbit; b->signbit = PLUS;

    for (i = a->lastdigit; i >= 0; i--) {
        //cout << i <<endl;
        digit_shift(&row, 1);
        // cout <<"last digit: " <<row.lastdigit << endl;
        row.digits[0] = a->digits[i];
        c->digits[i] = 0;
        while (compare_bignum(&row, b) != PLUS) {
            // cout << "while" << endl;
            c->digits[i]++;
            subtract_bignum(&row, b, &tmp);
            row = tmp;
            // cout << "imprimindo row" << endl;
            //print_bignum(&row);
        }
    }
    // cout << "after"<<endl;
    zero_justify(c);
    a->signbit = asign;
    b->signbit = bsign;
    r = &row;
    zero_justify(r);
    print_bignum(r);
}
//código acima retirado dos slides da matéria e adaptado ao problema


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    long long n;

    string s;
    bignum num;
    bignum ene;
    bignum thrash;
    bignum rest;

    cin >> t;
    
    // cout << "Ola"<<endl;
    while (t--) {
        cin >> n;
        cin >> s;
        // cout << "Ola"<<endl;
        str_to_bignum(s,&num);
        //print_bignum(&num);
        // cout << "Ola"<<endl;
        ll_to_bignum(n,&ene);
        //print_bignum(&ene);
        // cout << "Ola"<<endl;
        divide_bignum(&num,&ene,&thrash, &rest);
        // cout << "Ola"<<endl;
        // cout << "imprimindo resposta: "<< endl;
        // print_bignum(&rest);

        // s para bignum
    }

    return 0;
}