#include <iostream>

using namespace std;

int n,m,p[1001],q[1001],s[1001],ns,i;

int main()
{
    cin>>n;
    for(i=0; i<=n; i++)
        cin>>p[i];
    cin>>m;
    for(i=0; i<=m; i++)
        cin>>q[i];
    if(n>m) ns=n;
    else ns=m;
    for(i=0; i<=ns; i++)
        s[i]=p[i]+q[i];
    for(i=0; i<=ns; i++)
        cout<<s[i]<<" ";
    return 0;
}
