#include <iostream>

using namespace std;


int a[101],n,k;

void deletepoz(int poz)
{ for(int i=poz; i<n; i++)
     a[i]=a[i+1];
  n--;
}

int main()

{   int i;
    cin>>n;
    for(i=1; i<=n; i++)
        cin>>a[i];
    cin>>k;
    for(i=1; i<=n; i++)
        if(a[i]==k)
          { deletepoz(i);
            i--;
          }
    for(i=1; i<=n; i++)
       cout<<a[i]<<" ";
    return 0;
}
