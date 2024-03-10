#include <iostream>

using namespace std;

struct nod
{ int info;
  nod *urm;
};

nod *prim1,*ultim1;
nod *prim2,*ultim2;
nod *prim3,*ultim3;


void AdaugaFinal(nod*&prim, nod*&ultim,int x)
{nod *p=new nod;
 p->info=x;
 p->urm=NULL;
 if(prim==0) prim=ultim=p;
 else {ultim->urm=p; ultim=p;}

}

void CreareLista(nod*&prim, nod*&ultim)
{int n,x,i;
 cin>>n;
 for(i=1; i<=n; i++)
    {cin>>x;
     AdaugaFinal(prim,ultim,x);
    }
}

void StergePrim(nod *&prim)
{ nod* p=prim;
 prim=prim->urm;
 delete p;
}

void Interclasare(nod *prim1,nod *prim2,nod *&prim3,nod *&ultim3)
{prim3=ultim3=0;
 while(prim1 && prim2)
    if(prim1->info<prim2->info)
        {AdaugaFinal(prim3,ultim3,prim1->info);
         StergePrim(prim1);
        }
    else {AdaugaFinal(prim3,ultim3,prim2->info);
          StergePrim(prim2);
         }
  while(prim1!=0)
    {AdaugaFinal(prim3,ultim3,prim1->info);
     StergePrim(prim1);
    }
  while(prim2!=0)
    {AdaugaFinal(prim3,ultim3,prim2->info);
     StergePrim(prim2);
    }
}

void AfisareLista(nod *prim)
{for(nod *p=prim; p!=NULL; p=p->urm)
   cout<<p->info<<" ";
 cout<<"\n";
}



int main()
{

    CreareLista(prim1,ultim1);
    CreareLista(prim2,ultim2);
    Interclasare(prim1,prim2,prim3,ultim3);
    AfisareLista(prim3);
    return 0;
}
