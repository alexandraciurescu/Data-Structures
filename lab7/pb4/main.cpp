#include <iostream>

using namespace std;

///sortarea prin numarare


int main()
{
    int n,v[10005],i,f[10001]={0};
    cin>>n;
    for(i=1; i<=n; i++)
       {cin>>v[i];
        f[v[i]]++;
       }
    for(i=0; i < 10001; i++)
        while(f[i]--)
            cout<<i<<" ";
    return 0;
}
