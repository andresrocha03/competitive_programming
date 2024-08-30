#include<bits/stdc++.h>
using namespace std;
int main() {
    

    int n,m;
    
    double sum;
    scanf("%d%d",&m,&n);
    sum=m;
    for(int i=1;i<m;i++) {
        sum-=pow((double)1.0-(double)i/m,(double)n);
    }
    printf("%.12lf\n",sum);
    return 0;
}