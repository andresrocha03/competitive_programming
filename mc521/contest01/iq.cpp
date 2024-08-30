#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{    
    std::vector < int > v;
    int x=0,answer=0,evenness=-1,size=0,number=0,y=0;

    cin >> size;
    for (int i=0; i<size; i++){
        cin >> number;
        v.push_back(number);
    }
    
    x = v[0];
    y = v[1];
    if ((x%2 == 0) && (y%2 == 0)) {
        evenness = 1;
    } 
    else if ((x%2 != 0) && (y%2 != 0)){
        evenness = 0;
    }
    else if (((x%2 != 0) && (y%2 == 0)) || ((x%2 == 0) && (y%2 != 0)) ){
        y = v[2];
        if ((x%2 == 0) && (y%2 == 0)) {
        evenness = 1;
        } 
        else if ((x%2 != 0) && (y%2 != 0)){
            evenness = 0;
        }   
    }

    for (int i=0; i <= size; i++){
        x = v[i];
        if ((x%2 == 0) && (evenness==0)) {
            answer = i;
            break;
        } 
        else if ((x%2 != 0) && (evenness==1)) {
            answer = i;
            break;
        }
    }
    
    
    cout << answer+1;
    
}