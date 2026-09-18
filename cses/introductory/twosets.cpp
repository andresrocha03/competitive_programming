#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    if (n<3) {
        cout << "NO\n";
    }
    else if (n==3) {
        cout << "YES\n";
        cout << "2\n";
        cout << "1 2\n";
        cout << "1\n";
        cout << "3\n";
    }
    else if (n%2 != 0) {
        if ((n-3)%4==0) {
            cout << "YES\n";
            cout << ((n-3)/2) + 2 << "\n";
            cout << "1 " << "2 ";
            int x = n;
            int y = 4;
            for (int i=0;i<(n-3)/4;i++) {
                cout << x << " " << y << " ";
                x--;
                y++;
            }
            cout << "\n";
            cout << ((n-3)/2) + 1 << "\n";
            cout << "3 ";
            for (int i=0;i<(n-3)/4;i++) {
                cout << x << " " << y << " ";
                x--;
                y++;
            }
            cout << "\n";
        }
        else cout << "NO\n";
    }
    else {
        if (n%4==0) {
            cout << "YES\n";
            int x = n;
            int y = 1;
            cout << (n/2) << "\n";
            for (int i=0;i<n/4;i++) {
                cout << x << " " << y << " ";
                x--;
                y++;
            }
            cout << "\n";
            cout << (n/2) << "\n";
            for (int i=0;i<n/4;i++) {
                cout << x << " " << y<< " ";
                x--;
                y++;
            }
        }
        else cout << "NO\n";
    }
    return 0;
}