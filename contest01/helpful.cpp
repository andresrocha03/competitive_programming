#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{    
    std::string s1;
    std::vector < int > arr;
    string numbers[100];
    
    cin >> s1;
    
    for (auto& x : s1) { 
        if (x != '+') {
            arr.push_back(int(x)-48);
        }
    } 
    sort(arr.begin(),arr.end());

    for (int i=0; i<arr.size() - 1; i++){
        cout << arr[i] << "+";
    }
    cout<< arr[arr.size()-1];
    
}