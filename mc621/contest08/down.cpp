#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    float t, b,t1,a1, t2, a2;
    cin >> t;
    
    while (t--) {
        cin >> b >> t1 >> a1 >> t2 >> a2;
        float ans1=0, ans2=0, timer=0;

        while (a1 >0  || a2>0) {
            if (t1<=timer && t2 > timer) {
                if (a1 > 0) {
                    if (b>a1) {
                        ans1 += a1/b;
                        a1 -= b;
                    }           
                    else {
                        ans1 += 1;      
                        a1 -= b;
                    }
                }
            }
            if (t1<=timer && t2 <= timer) {
                cout << "ans1: "<< ans1 << " ans2: " << ans2 << "\n";
                if (a1 > 0) {
                    if (a2 > 0) {
                        if ((b/2)>a1) {
                            ans1 += (a1/(b/2));
                            a1 -= (b/2);
                        }           
                        else {
                            ans1 += 1;      
                            a1 -= (b/2);
                        }
                        timer += 
                    }
                    else {
                        if (b>a1) {
                            ans1 += (a1/b);
                            a1 -= b;
                        }           
                        else {
                            ans1 += 1;      
                            a1 -= b;
                        }
                    }
                
                }
                if (a2 > 0) {
                    if (a1 > 0) {
                        if (b>a2) {
                            // cout << "a2 " << a2 << "\n";
                            // cout << "b/2 " << b/2 << "\n";
                            ans2 += (a2/(b/2));
                            // cout << ans2 << "\n";
                            a2 -= (b/2);
                        }           
                        else {
                            ans2 += 1;      
                            a2 -= (b/2);
                        }
                    }
                    else {
                        if (b>a2) {
                            ans2 += (a2/b);
                            a2 -= b;
                        }           
                        else {
                            ans2 += 1;      
                            a2 -= b;
                        }
                    }
                }
            }
            if (t1 > timer && t2 <= timer) {
                if (a2 > 0) {
                    if (b>a2) {
                        ans2 += (a2/b);
                        a2 -= b;
                    }           
                    else {
                        ans2 += 1;      
                        a2 -= b;
                    }
                }
           }
            timer+= ; 
        }
        cout << ans1 << " " << ans2 << "\n";
    }




}