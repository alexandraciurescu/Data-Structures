#include <iostream>

using namespace std;

int a[10000];

void MS(int v[], int st, int dr)
{
	if(st<dr)
	{
		int mij=(st+dr)/2;
		MS(v,st,mij);
		MS(v,mij+1,dr);

		int i=st, j=mij+1, k=0;
		while(i<=mij && j<=dr)
			if(v[i]< v[j])
				a[++k]=v[i++];
			else a[++k]=v[j++];
		while(i<=mij)
			a[++k]=v[i++];
		while(j<=dr)
			a[++k]=v[j++];
		for(i=st, j= 1; i<= dr; i++, j++)
			v[i]=a[j];
	}
}

int main()
{
    //merge sort
    int v[10000],n,i;
    cin>>n;
    for(i=1; i<=n; i++)
        cin>>v[i];
    MS(v,1,n);
    for(i=1; i<=n; i++)
        cout<<v[i]<<" ";
    return 0;
}
