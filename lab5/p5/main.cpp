#include <iostream>
#include <cstring>
#define N 10005


using namespace std;

struct nod
{ int info;
  nod *urm;
};

nod *prim1,*ultim1;
nod *prim2,*ultim2;
nod *prim3,*ultim3;


void AdaugaFinal(nod*&prim, nod*&ultim,int x)
{nod *p=new nod;
 p->info=x;
 p->urm=NULL;
 if(prim==0) prim=ultim=p;
 else {ultim->urm=p; ultim=p;}

}

void CreareLista(char s[],nod*&prim, nod*&ultim)
{int n=strlen(s);
 prim=ultim=0;
 for(int i=n-1; i>=0; i--)
    AdaugaFinal(prim,ultim,s[i]-'0');
}

void Suma(nod*prim1,nod*prim2,nod*&prim3,nod*&ultim3)
{prim3=ultim3=0;
 int carry=0;
 nod *p=prim1, *q=prim2;
 while(p && q)
   {carry=carry+p->info+q->info;
    AdaugaFinal(prim3,ultim3,carry%10);
    carry=carry/10;
    p=p->urm;
    q=q->urm;
   }
 while(p)
   {carry=carry+p->info;
    AdaugaFinal(prim3,ultim3,carry%10);
    carry=carry/10;
    p=p->urm;
   }
 while(q)
   {carry=carry+q->info;
    AdaugaFinal(prim3,ultim3,carry%10);
    carry=carry/10;
    q=q->urm;
   }
 if(carry>0) AdaugaFinal(prim3,ultim3,carry);
}

void AfisareLista(nod *p)
{if(p->urm) AfisareLista(p->urm);
 cout<<p->info;
}


int main()
{   char s[N];
    cin>>s;
    CreareLista(s,prim1,ultim1);
    cin>>s;
    CreareLista(s,prim2,ultim2);
    Suma(prim1,prim2,prim3,ultim3);
    AfisareLista(prim3);
    return 0;
}
