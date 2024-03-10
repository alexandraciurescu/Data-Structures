#include <iostream>
using namespace std;

struct nod
{ int info;
  nod *urm,  *ant;
};

bool Empty(nod* stanga, nod* dreapta)
{ return stanga==NULL;}

void PushLeft(nod* &stanga, nod* &dreapta, int x)
{ nod *nou = new nod;
  nou->info=x;
  if(Empty(stanga,dreapta))
     {  nou->urm=0; nou->ant=0;
        stanga=nou; dreapta=nou;
     }
  else
     {  nou->ant=0; nou->urm=stanga;
        stanga->ant=nou; stanga=nou;
     }
}

void PushRight(nod* &stanga, nod* &dreapta, int x)
{ nod *nou = new nod;
  nou->info=x;
  if(Empty(stanga,dreapta))
     {  nou->urm=NULL; nou->ant=NULL;
        stanga=nou; dreapta=nou;
     }
  else
     {  nou->urm=NULL; nou->ant=dreapta;
        dreapta->urm=nou; dreapta=nou;
     }
}

int PopLeft(nod* &stanga, nod* &dreapta)
{ if(Empty(stanga,dreapta)) return -1;
  nod *p=stanga;
  int x=stanga->info;
  stanga=stanga->urm;
  if(stanga==NULL) stanga=dreapta=NULL;
  else stanga->ant=NULL;
  delete p;
  return x;
}

int PopRight(nod* &stanga, nod* &dreapta)
{ if(Empty(stanga,dreapta)) return -1;
  nod *p=dreapta;
  int x=dreapta->info;
  dreapta=dreapta->ant;
  if(dreapta==NULL) stanga=dreapta=NULL;
  else dreapta->urm=NULL;
  delete p;
  return x;
}

int PeekLeft(nod* stanga, nod* dreapta)
{ if(Empty(stanga,dreapta)) return -1;
  else return stanga->info;
}

int PeekRight(nod* stanga, nod* dreapta)
{ if(Empty(stanga,dreapta)) return -1;
  else return dreapta->info;
}

void Afisare(nod* stanga, nod* dreapta)
{ if(Empty(stanga,dreapta)) cout<<"Coada vida\n";
  else
  {  cout<<"stanga ";
     for(nod *p=stanga; p!=NULL; p=p->urm)
           cout<<p->info<<" ";
     cout<<"dreapta\n";
  }
}

int main()
{   nod *stanga=NULL, *dreapta=NULL;
    Afisare(stanga,dreapta);
    PushLeft(stanga,dreapta,1);
    PushLeft(stanga,dreapta,2);
    PushLeft(stanga,dreapta,3);
    Afisare(stanga,dreapta);
    PushRight(stanga,dreapta,1);
    PushRight(stanga,dreapta,2);
    PushRight(stanga,dreapta,3);
    Afisare(stanga,dreapta);
    PopLeft(stanga,dreapta);
    PopRight(stanga,dreapta);
    Afisare(stanga,dreapta);
    return 0;
}
