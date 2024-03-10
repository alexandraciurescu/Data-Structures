#include <bits/stdc++.h>

using namespace std;

int a[100002];
int n;

int pivot(int st, int dr)
{int i=st,j=dr,pasi=0,pasj=1;
 while(i<j)
   {if(a[i]>a[j])
      {swap(a[i],a[j]);
       swap(pasi,pasj);
      }
    i=i+pasi;
    j=j-pasj;
   }
 return i;
}

void Qsort(int st, int dr)
{if(st<dr)
   {int m=pivot(st,dr);
    Qsort(st,m-1);
    Qsort(m+1,dr);
   }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    Qsort(1,n);
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
   return 0;
}
