#include <iostream>

using namespace std;

int main()
{
    int n,t,a[201],b[101],i,poz,j,k;
    cin>>n;
    for(i=1; i<=n; i++)
        cin>>a[i];
    cin>>k;
    cin>>t;
    for(i=1; i<=t; i++)
        cin>>b[i];

    for(i=1; i<=n; i++)
        if(a[i]==k)
         {poz=i;
          break;
         }

    poz++;
    n=n+t;
    for(i=n; i>=poz; i--)
        a[i+t]=a[i];
    j=1;
    for(i=poz; i<=poz+t-1; i++)
        {a[i]=b[j]; j++;}

    for(i=1; i<=n; i++)
        cout<<a[i]<<" ";

    return 0;
}
