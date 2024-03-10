#include <iostream>

using namespace std;

int main()
{
    int i,n,x,y;
    cin>>n;
    cin>>x;
    for(i=2; i<=n; i++)
        {cin>>y;
         x=x^y;
        }
    cout<<x;
    return 0;
}
