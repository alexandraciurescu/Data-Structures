#include<iostream>
using namespace std;

void CountSort(int v[], int n, int div)
{
    int nou[10001];
    int f[10]={0};

    for (int i=0; i<n; i++)
        f[(v[i]/div)%10]++;

    for (int i=1; i<10; i++)
        f[i]+=f[i-1];

    for (int i=n-1; i>=0; i--)
    {
        nou[f[(v[i]/div)%10]-1] = v[i];
        f[(v[i]/div)%10]--;
    }

    for (int i=0; i<n; i++)
        v[i]=nou[i];
}


void RadixSort(int v[], int n)
{
    int vmax=v[0];
    for (int i=1; i<n; i++)
        if (v[i]>vmax)
            vmax=v[i];
    for (int div=1; vmax/div>0; div*=10)
        CountSort(v,n,div);
}


int main()
{
	int n,v[10001],i;
	cin>>n;
	for(i=0; i<n; i++)
        cin>>v[i];

	RadixSort(v, n);

	for(i=0; i<n; i++)
        cout<<v[i]<<" ";


    return 0;
}
