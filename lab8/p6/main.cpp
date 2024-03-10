/// Depou
#include <iostream>
#define N 101
using namespace std;

struct nod
{   int info;
    nod *urm;
};

/// vom codifica liniile cu: intrare (11), iesire (22), cele k linii auxiliare (1,2,...k)
struct solutie
{ int sursa, destinatie;
  int vagon;
};

int n; /// numarul de vagoane

solutie mutare[N];  /// solutia
int m;

/// adresele primelor si ultimelor noduri celor k cozi asociate celor k linii auxiliare
nod *prim[N];
nod *ultim[N];

void Push(nod *&prim, nod* &ultim, int x)
{ nod *nou=new nod;
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

void MutareVagoane()
{ int n, k, x;
  int urmator=1; /// vagonul care trebuie sa urmeza pe linia de iesire
  cout<<"n=";cin>>n;
  cout<<"k="; cin>>k;
  for(int i=1; i<=n; i++)
     {  /// preluam un vagon de pe linia de intrare
        cout<<"Vagonul: "; cin>>x;
        /// verificam daca poate fi dus direct pe linia de iesire
        if(urmator==x)
           { /// memoram mutarea de pe linia de intrare pe cea de iesire
             m++; mutare[m].sursa=11; mutare[m].destinatie=22; mutare[m].vagon=x;
             urmator++;
             /// de fiecare data cand ducem un vagon pe linia finala le ducem si pe toate
             /// care se afla pe liniile de asteptare si in sfarsit pot fi duse pe linia finala
             bool ok=1;
             while(ok)
                {   ok=0;
                    for(int j=1; j<=k; j++) /// pentru fiecare linie auxiliara j
                    {  nod *p=prim[j]; /// parcurgem vagoanele de pe linia j
                       while(!Empty(prim[j],ultim[j]))
                           { int x=Peek(prim[j],ultim[j]);
                             if(x==urmator) /// vagonul poate fi mutat
                                { m++; mutare[m].sursa=j; mutare[m].destinatie=22; mutare[m].vagon=x;
                                  urmator++;
                                  Pop(prim[j],ultim[j]); /// stergem din coada
                                  ok=1;
                                }
                             else break;
                           }
                    }
                }
           }
        else
           { /// va fi dus temporar pe una din liniile auxiliare
             /// prima linie disponibila pe care fie nu se afla nici-un vagon in asteptare
             /// sau se afla vagoane cu valori mai mici (ca sa poata fi mutate)
             int linie, libera, vagultim=1e6;
             bool ok1=0, ok2=0;
             for(int j=1; j<=k; j++)
                 if(!Empty(prim[j],ultim[j]))
                     {  if(ultim[j]->info < x && ultim[j]->info < vagultim)
                         { linie=j; vagultim=ultim[j]->info; ok1=1;}
                     }
                 else libera=j, ok2=1;
             if(ok1==1) /// se poate adauga dupa un alt vagon pe o linie auxiliara
                 { m++; mutare[m].sursa=11; mutare[m].destinatie=linie; mutare[m].vagon=x;
                   Push(prim[linie],ultim[linie],x);
                 }
             else if(ok2==1) /// se poate adauga pe linie auxiliara goala
                   { m++; mutare[m].sursa=11; mutare[m].destinatie=libera; mutare[m].vagon=x;
                     Push(prim[libera],ultim[libera],x);
                   }
                  else /// nu avem unde sa ducem vagonul curent ca sa ajungem la o solutie finala
                    {m=0; return;}
           }
     }
}


void Afisare()
{ if(m==0) cout<<"Imposibil";
  else
     { cout<<"Sunt "<<m<<" mutari\n";
       for(int i=1; i<=m; i++)
          {  if(mutare[i].sursa==11) cout<<"de la intrare ";
             else cout<<"de pe linia auxiliara "<<mutare[i].sursa<<" ";
             if(mutare[i].destinatie==22) cout<<"la linia de sosire ";
             else cout<<"la linia auxiliara "<<mutare[i].destinatie<<" ";
             cout<<"se muta vagonul "<<mutare[i].vagon<<"\n";
          }
     }
}

int main()
{
    MutareVagoane();
    Afisare();
    return 0;
}
