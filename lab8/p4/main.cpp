/// Parantezare corecta
#include <iostream>
#include <cstring>
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

bool test(int a[], int n)
{ nod *top=NULL;
  for(int i=1; i<=n; i++)
    if(Empty(top)) Push(top,a[i]);
    else if(Peek(top)==a[i]) Pop(top);
         else Push(top,a[i]);
  return Empty(top);

}

int main()
{
    int n, a[101];
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    if(test(a,n)) cout<<"valid";
    else cout<<"invalid";
    return 0;
}
