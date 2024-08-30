#include <bits/stdc++.h>
using namespace std;
int t,n,k;
pair<int,int> arr[100005];

int main() {
    cin >> t;
    while (t--){cin>>n>>k;
    for (int i=0;i<n;i++){
        cin>>arr[i].first;	
        arr[i].second=i;
    }
    sort(arr,arr+n);
    for(int i=1;i<n;i++) {
        if (arr[i-1].second+1!=arr[i].second) k--;
    }
    puts(k>0 ? "Yes" :"No");}
}