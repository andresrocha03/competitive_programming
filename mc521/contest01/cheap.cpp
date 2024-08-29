#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{    
    int n,m,a,b,price1=0,price2=0,min;
    cin >> n;
    cin >> m;
    cin >> a;
    cin >> b;

    //price1
    price1 = n*a;
    min = price1;
    //price2
    //price2 = (n/m)*b + (n%m)*a;

    for (int i=1; i <= (n/m)+1 ; i++){
        if (n>(i*m)){
            price2 = i*b + (n-(i*m))*a;
        }
        else {
            price2 = i*b;
        }
        if (price2<min){
            min =price2;
        }
    }

    cout << min;
    
}  