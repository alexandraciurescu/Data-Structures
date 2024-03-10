#include <iostream>

using namespace std;

struct nod
{int info;
 nod *urm;
};

nod *prim,*ultim;

void Inserare(nod *&prim, int x)
{nod *p=new nod;
 p->info=x;
 if(prim==0) {p->urm=0; prim=p; return;}
 if(p->info<=prim->info) {p->urm=prim; prim=p; return;}
 nod *q=prim;
 while(q->urm!=NULL && q->urm->info<x)
    q=q->urm;
 p->urm=q->urm;
 q->urm=p;

}

void AfisareLista(nod *prim)
{for(nod *p=prim; p!=0; p=p->urm)
   cout<<p->info<<" ";
 cout<<"\n";

}

void CreareLista(nod *&prim)
{int n,x,i;
 cin>>n;
 for(i=1;i<=n;i++)
    {cin>>x;
     Inserare(prim,x);
     AfisareLista(prim);
    }
}


int main()
{
    CreareLista(prim);
    return 0;
}
