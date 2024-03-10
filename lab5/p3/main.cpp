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

void AdaugaFata(nod *&prim, int x)
{nod *p=new nod;
 p->info=x;
 p->urm=prim;
 prim=p;
}


void InversareNoduri(nod*&prim)
{nod *prim2=0;
 for(nod *p=prim; p!=0; p=p->urm)
    AdaugaFata(prim2,p->info);
 ///eliberam spatiul de memorie alocat listei initiale
 while(prim!=0)
   {nod *p=prim;
    prim=prim->urm;
    delete p;
   }
  prim=prim2;
}



int main()
{

    CreareLista();
    AfisareLista(prim);
    InversareNoduri(prim);
    AfisareLista(prim);
    return 0;
}
