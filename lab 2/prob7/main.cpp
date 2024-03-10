#include <iostream>

using namespace std;

int n,m,p[1001],q[1001],s[1001],ns,i,j;

int main()
{
    cin>>n;
    for(i=0; i<=n; i++)
        cin>>p[i];
    cin>>m;
    for(i=0; i<=m; i++)
        cin>>q[i];

    ns=n+m;
    for(i=0; i<=n; i++)
        for(j=0; j<=m; j++)
           s[i+j]=s[i+j]+p[i]*q[j];

    for(i=0; i<=ns; i++)
        cout<<s[i]<<" ";
    return 0;
}
