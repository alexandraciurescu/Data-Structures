/// Stiva alocata dinamic
#include <iostream>
using namespace std;

struct nod
{
    int info;
    nod *urm;
};

void Push(nod *&top, int x)
{nod *nou=new nod;
 nou->info=x;
 nou->urm=top;
 top=nou;
}

int Pop(nod *&top)
{if(top==NULL) return -1;
 else
    { nod *p=top;
      int x=top->info;
      top=top->urm;
      delete p;
      return x;
    }
}

int Peek(nod* top)
{
    if(top==NULL) return -1;
    else return top->info;
}

bool Empty(nod * top)
{
    return top==NULL;
}

int Search(nod *top, int x)
{ int ct=0;
  for(nod *p=top; p!=NULL; p=p->urm)
    if(p->info==x) return ct;
    else ct++;
  return -1;
}

void Afisare(nod *top)
{ if(!Empty(top))
    {cout<<"varf ";
     for(nod *p=top; p!=NULL; p=p->urm)
        cout<<p->info<<" ";
     cout<<"baza\n";
    }
  else cout<<"Stiva vida\n";
}

int main()
{
    nod *top=NULL;
    Afisare(top);
    Push(top,1);
    Push(top,2);
    Push(top,3);
    Afisare(top);
    cout<<Search(top,2)<<"\n";
    cout<<Search(top,4)<<"\n";
    cout<<Empty(top)<<"\n";
    cout<<Pop(top)<<"\n";
    Afisare(top);
    cout<<Peek(top)<<"\n";
    Afisare(top);
    Pop(top);
    Pop(top);
    Afisare(top);
    cout<<Pop(top)<<"\n";
    cout<<Empty(top)<<"\n";

    return 0;
}
