#include <iostream>

using namespace std;

int main()
{
    int n,a[101],i,vmin,vmax,mini,maxi;
    cin>>n;
    for(i=1; i<=n; i++)
        cin>>a[i];

    vmin=1000000; vmax=-1000000;
    for(i=1; i<=n/2; i++) /// luam perechi de elemente simetrice
       {  if(a[i]<a[n+1-i]) mini=a[i], maxi=a[n+1-i];
          else mini=a[n+1-i], maxi=a[i];
          if(mini<vmin) vmin=mini;       /// numar comparatii [n/2] * 3
          if(maxi>vmax) vmax=maxi;

       }

    if(n%2==1) /// numar impar de elemente
     { if(a[n/2+1]<vmin) vmin=a[n/2+1];
       if(a[n/2+1]>vmax) vmax=a[n/2+1];
     }

    cout<<vmin<<" "<<vmax;
    return 0;
}
