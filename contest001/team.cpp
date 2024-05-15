#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{    
    std::vector < int > v;
    std::vector < int > one;
    std::vector < int > two;
    std::vector < int > three;
    std::vector < int > qtd;
    int min=0,index=0,j=0;
    int size=0,number=0;
   
   
    for (int i=0;i<4;i++) {
        qtd.push_back(0);    
    }
   
    //input
    cin >> size;
    for (int i=0; i<size; i++){
        cin >> number;
        v.push_back(number);
    }
    
    //read vector
    for (int i=0; i<size; i++) {
        if (v[i]==1) {
            qtd[1]++;
            one.push_back(i);
        }
        else if (v[i]==2) {
            qtd[2]++;
            two.push_back(i);
        }
        else if (v[i]==3) {
            qtd[3]++;
            three.push_back(i);
        }
    }

   

    //take decisions
    if (qtd[1]==0 || qtd[2]==0 || qtd[3]==0) {
        cout << 0; //not possible to form teams
    }
    else {
        
        min = qtd[1];
        index = 1;
        
        for (int i=1; i<=3; i++) {
            if (qtd[i] < min){
                min = qtd[i];
                index = i;
            }
        }
        cout << min << "\n";
        for (int i=1; i<=min; i++) {
            cout << one[j] +1 << " ";
            cout << two[j] +1<< " ";
            cout << three[j] +1<< " ";
            if (i != min) {cout << "\n";}
            j++;
        }

    }
    
    
    
}