/// Coada alocata dinamic
#include <iostream>
using namespace std;

struct nod
{
    int info;
    nod *urm;
};

void Push(nod *&prim, nod* &ultim, int x)
{ nod * nou=new nod;
  nou->info=x;
  nou->urm=NULL;
  if(prim==NULL) prim=ultim=nou;
  else {ultim->urm=nou; ultim=nou;}
}

int Pop(nod *&prim, nod* &ultim)
{if(prim==NULL) return -1;
 else
    { nod *p=prim;
      int x=prim->info;
      prim=prim->urm;
      delete p;
      if(prim==NULL) ultim=NULL;
      return x;
    }
}

int Peek(nod* prim, nod* ultim)
{
    if(prim==NULL) return -1;
    else return prim->info;
}

bool Empty(nod * prim, nod* ultim)
{
    return prim==NULL;
}

int Search(nod *prim, nod* ultim, int x)
{ int ct=0;
  for(nod *p=prim; p!=NULL; p=p->urm)
     {   ct++;
         if(p->info==x) return ct;
     }
  return -1;
}

void Afisare(nod *prim, nod* ultim)
{ if(!Empty(prim,ultim))
    {cout<<"out ";
     for(nod *p=prim; p!=NULL; p=p->urm)
        cout<<p->info<<" ";
     cout<<"in\n";
    }
  else cout<<"Coada vida\n";
}

int main()
{
    nod *prim=NULL, *ultim=NULL;
    Afisare(prim,ultim);
    Push(prim,ultim,1);
    Push(prim,ultim,2);
    Push(prim,ultim,3);
    Afisare(prim,ultim);
    cout<<Search(prim,ultim,2)<<"\n";
    cout<<Search(prim,ultim,4)<<"\n";
    cout<<Empty(prim,ultim)<<"\n";
    cout<<Pop(prim,ultim)<<"\n";
    Afisare(prim,ultim);
    cout<<Peek(prim,ultim)<<"\n";
    Afisare(prim,ultim);
    Pop(prim,ultim);
    Pop(prim,ultim);
    Afisare(prim,ultim);
    cout<<Pop(prim,ultim)<<"\n";
    cout<<Empty(prim,ultim)<<"\n";

    return 0;
}
