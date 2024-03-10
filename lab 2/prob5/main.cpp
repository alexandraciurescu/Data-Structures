#include <iostream>

using namespace std;

int main()
{
    int n,t,a[1001],s=0,p=1,i;
    cin>>n;
    for(i=0; i<=n; i++)
        cin>>a[i];
    cin>>t;
    for(i=0; i<=n; i++)
        {s=s+p*a[i];
         p=p*t;
        }
    cout<<s;
    return 0;
}
