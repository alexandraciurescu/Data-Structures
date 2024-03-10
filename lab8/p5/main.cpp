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


void Citire(int a[][101], int &n)
{   cin>>n;
    for(int i=1; i<=n; i++)
       for(int j=1; j<=n; j++) cin>>a[i][j];
}

void Fill(int a[][101], int n, int x, int y, int color)
{ nod *primL=NULL, *ultimL=NULL; /// coada pentru indicii liniilor
  nod *primC=NULL, *ultimC=NULL; /// coada pentru indicii coloanelor
  int l,c;

  a[x][y]=color;
  Push(primL,ultimL,x);
  Push(primC,ultimC,y);

  while(!Empty(primL,ultimL))
  {  l=Pop(primL,ultimL);
     c=Pop(primC,ultimC);
     /// cei patru vecini
     if(l-1>=1 && a[l-1][c]==1) {a[l-1][c]=color; Push(primL,ultimL,l-1); Push(primC,ultimC,c);}
     if(l+1<=n && a[l+1][c]==1) {a[l+1][c]=color; Push(primL,ultimL,l+1); Push(primC,ultimC,c);}
     if(c-1>=1 && a[l][c-1]==1) {a[l][c-1]=color; Push(primL,ultimL,l); Push(primC,ultimC,c-1);}
     if(c+1<=n && a[l][c+1]==1) {a[l][c+1]=color; Push(primL,ultimL,l); Push(primC,ultimC,c+1);}
  }
}

void Colorare(int a[][101], int n)
{  int color=2; /// culori = 2,3....
   for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++)
         if(a[i][j]==1)
            { Fill(a,n,i,j,color);
              color++;
            }

}

void Afisare(int a[][101], int n)
{ for(int i=1; i<=n; i++)
   { for(int j=1; j<=n; j++) cout<<a[i][j]<<" ";
     cout<<"\n";
   }
}

int main()
{
    int a[101][101],n;
    Citire(a,n);
    Colorare(a,n);
    Afisare(a,n);
    return 0;
}
