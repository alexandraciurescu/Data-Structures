#include <iostream>
using namespace std;

struct nod
{ int info;
  nod *urm;

};

bool Empty(nod *prim, nod *ultim)
{ return prim==NULL;}

void Insert(nod *&prim, nod *&ultim, int x)
{ nod *nou=new nod;
  nou->info=x;
  if(prim==NULL) {nou->urm=NULL; prim=ultim=nou;}
  else if(x<=prim->info) {nou->urm=prim; prim=nou;}
       else if(x>=ultim->info) {ultim->urm=nou; nou->urm=NULL; ultim=nou;}
            else
               { nod *p=prim;
                 while(p->urm && p->urm->info<x) p=p->urm;
                 nou->urm=p->urm;
                 p->urm=nou;
               }
}


void Afisare(nod *prim, nod *ultim)
{ if(Empty(prim,ultim))
    cout<<"Coada vida\n";
  else
    { cout<<"stanga ";
      for(nod *p=prim; p!=NULL; p=p->urm)
            cout<<p->info<<" ";
      cout<<"dreapta\n";
    }
}


int main()
{   nod *prim=0, *ultim=0;
    Insert(prim,ultim,3);
    Afisare(prim,ultim);
    Insert(prim,ultim,1);
    Afisare(prim,ultim);
    Insert(prim,ultim,10);
    Afisare(prim,ultim);
    Insert(prim,ultim,7);
    Afisare(prim,ultim);
    return 0;
}
