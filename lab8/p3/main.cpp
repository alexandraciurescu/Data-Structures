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

bool ParantezareCorecta(char s[])
{ nod *top=NULL;
  for(int i=0; i<strlen(s); i++)
    if(s[i]=='(') Push(top,1);
    else if(Empty(top)) return 0;
         else {int x=Pop(top);}
  return Empty(top);


}

int main()
{
    char s[101];
    cin>>s;
    if(ParantezareCorecta(s)) cout<<"corect";
    else cout<<"incorect";


    return 0;
}
