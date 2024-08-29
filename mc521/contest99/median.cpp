#include<bits/stdc++.h>
using namespace std;
long long i,k,n,s,t,a[200005];
int main()
{
for(cin>>t;t--;)
{
cin>>n>>k;
for(i=s=0;i<n*k;i++){
    cin>>a[i];
}
for(i=(n-1)/2*k;i<n*k;i+=n/2+1){
    s+=a[i];
}
cout<<s<<"\n";
}
}