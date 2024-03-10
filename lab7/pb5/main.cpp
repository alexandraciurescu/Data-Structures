#include<iostream>

using namespace std;


void insert(int H[],int n,int x)
{n++;
 int fiu=n;
 int tata=n/2;
 while (tata && H[tata]<x)
      {H[fiu]=H[tata];
       fiu=tata; tata=fiu/2;
      }
 H[fiu]=x;
}

void CreareHeap(int H[], int &n)
{int i,x;
 cin>>n;
 for(i=1; i<=n; i++)
    {cin>>x;
     if(i==1) H[1]=x;
     else insert(H,i-1,x);
    }
}

void display(int H[], int n)
{int i;
 for(i=1; i<=n; i++)
    cout<<H[i]<<" ";
}


int main()
{   int H[10001],n;
	CreareHeap(H,n);
	display(H,n);
	return 0;
}
