#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> arr(2*n);


    for (int i = 0; i < 2 * n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        arr[i].first = x;
        arr[i].second = y;
    }


    int tam = arr.size();
    //bool flag = true;

    int z;
    cin >> z;
    //for (int a = -500; a++; a < 500)
    //{
        //for(int b = -500; b++; b < 500){
        
            int cont = 0; // acima
            bool flag = true;
            for (int j = 0; j < tam; j++)
            {
          //      if(b == 0) break;
                int sum = -1 * -499 * arr[j].first * (1/-499);
                //cout << "second: " << arr[j].second << "\n";
                //cout << "sum " << sum << "\n";
                if (arr[j].second > sum)
                    cont++;
                    //cout << "cont: " << cont << "\n";
                if (arr[j].second == sum)
                {
                    flag = false;
                    break;
                }
                
            }

            if (cont == tam/2 && flag)
            {
                cout << "DEU BOM \n";
                //cout << a << " " << b << '\n';
                //break;
            }
        //}
    //}
}