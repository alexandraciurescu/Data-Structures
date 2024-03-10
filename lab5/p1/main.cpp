#include <iostream>

using namespace std;

struct nod
{ int info;
  nod *urm;
};

nod *prim,*ultim;

void AdaugaFinal(nod*&prim, nod*&ultim,int x)
{nod *p=new nod;
 p->info=x;
 p->urm=NULL;
 if(prim==0) prim=ultim=p;
 else {ultim->urm=p; ultim=p;}

}

void CreareLista()
{int n,x,i;
 cin>>n;
 for(i=1; i<=n; i++)
    {cin>>x;
     AdaugaFinal(prim,ultim,x);
    }
}

void AfisareLista(nod *prim)
{for(nod *p=prim; p!=NULL; p=p->urm)
   cout<<p->info<<" ";
 cout<<"\n";
}

void InserareNoduri(nod *prim,nod *ultim)
{for(nod *p=prim; p!=ultim; p=p->urm)
  {nod *q=new nod;
   q->info=(p->info+p->urm->info)/2;
   q->urm=p->urm;
   p->urm=q;
   p=q;
  }
}

int main()
{

    CreareLista();
    AfisareLista(prim);
    InserareNoduri(prim,ultim);
    AfisareLista(prim);
    return 0;
}
