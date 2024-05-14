#include <iostream> 
using namespace std; 

#define N 150005
int arr[N], sol[N],sum[N];
// Driver code 

int minSum(int arr[], int sol[], int n, int k) 
{  
    //subsequência de tamanho k começando em index com a menor soma 
    int min = __INT_MAX__;
    int index;
    
    if (n == 1) 
        return 1; 

    for (int i=1; i<=n; i++) {
        sum[i] = sum[i-1] + arr[i-1];
    }
    
    sol[1] = sum[k];
    
    for (int i = 1; i <= n-k+1; i++) { 
        sol[i] = sum[i+k-1] - sum[i-1]; 
    }
         
    //encontrar minimmo
    for (int i=1; i<=n-k+1; i++ ) {
        if (sol[i] < min) {
            min = sol[i];
            index = i;
        }
    }

    return index;
     
} 


int main() 
{ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k, x, index=1;

    cin >> n >> k;

    for (int i=0; i<n; i++) {
        cin >> x;
        arr[i] = x;
    } 

    cout << minSum(arr, sol, n, k); 
    return 0; 
} 
