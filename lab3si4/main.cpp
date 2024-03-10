#include <iostream>

using namespace std;

struct nod{
    int info;
    nod *urm;
};

void adi(nod*& prim, nod*&ultim, int x)
{ nod *p=new nod;
  p->info=x;
  p->urm=prim;
  if(prim==NULL) prim=ultim=p;
  else prim=p;
}

void adf(nod*& prim, nod*&ultim, int x)
{nod *p=new nod;
 p->info=x;
 p->urm=0;
 if(ultim==NULL) prim=ultim=p;
 else {ultim->urm=p; ultim=p;}
}

void af(nod *prim)
{nod *p;
 if(prim==NULL) cout<<"lista vida";
 for(p=prim; p!=0; p=p->urm)
       cout<<p->info<<" ";
 cout<<"\n";
}

int cv(nod *prim, int x)
{ int ct=0; nod *p=prim;
  while(p!=NULL)
    { ct++;
      if (p->info==x)
        return ct;
      p=p->urm;
    }
  return -1;
}

int cp(nod *&prim, int poz)
{int ct=0;
 nod *p=prim;
 while(p!=NULL)
   {ct++;
    if(ct==poz)
        return p->info;
    p=p->urm;
   }
  return -1;
}

void iv(nod *prim, nod*&ultim, int val, int nou)
{ nod *p=prim;
  ///aflam pozitia dupa care inseram
  while(p!=NULL)
    if(p->info==val) break;
    else p=p->urm;
  /// nu exista niciun nod cu informatia val
  if (p==NULL) return;

  /// inseram dupa nodul de adresa p
  nod *q=new nod;
  q->info=nou;
  q->urm=p->urm;
  p->urm=q;
  if(p==ultim) ultim=q;

}

void ip(nod *&prim, nod *&ultim, int i, int nou)
{nod *p=prim;
 /// caz particular inserare pozitia 1
 if(i==1) {adi(prim,ultim,nou); return;}

 int ct=1;
 while(ct!=i-1 && p!=NULL)
    {p=p->urm;
     ct++;
    }
 if(p==NULL) return;
 /// inseram la pozitia i
 nod *q=new nod;
 q->info=nou;
 q->urm=p->urm;
 p->urm=q;
}


void sv(nod *&prim, nod *&ultim, int val)
{nod *p=prim, *q=prim;
 while(p!=NULL && p->info!=val)
    { q=p;
      p=p->urm;
    }
 if(p==NULL) return;
 if(p==prim)
    {prim=prim->urm;
     delete p;
     if(prim==NULL) ultim=NULL; /// lista a ramas vida
    }
 else if(p==ultim)
         { q->urm=NULL;
           ultim=q;
           delete p;
         }
      else
        {q->urm=p->urm;
         delete p;
        }
}

void sp(nod *&prim, nod *&ultim, int poz)
{if(poz==1)
   {   nod *p=prim;
       prim=prim->urm;
       if(prim==NULL) ultim=NULL;
       delete p;
   }
 else
    {nod *p=prim;
     nod *q;
     int ct=1;
     while(p!=NULL && ct!=poz)
       {ct++;
        q=p;
        p=p->urm;
       }
     if(p==NULL)
        return;
     q->urm=p->urm;
     if(p==ultim) ultim=q;
     delete p;

    }
}



int main()
{
    nod *prim, *ultim;
    prim=ultim=NULL; ///initializare lista vida
    af(prim);
    adi(prim,ultim,1); adi(prim,ultim,2); adi(prim,ultim,3);
    af(prim);
    adf(prim,ultim,4);
    af(prim);
    cout<<cv(prim,5)<<"\n";
    cout<<cv(prim,1)<<"\n";
    cout<<cp(prim,5)<<"\n";
    cout<<cp(prim,3)<<"\n";
    sp(prim,ultim,1);
    af(prim);
    sp(prim,ultim,1);
    af(prim);
    sv(prim,ultim,4);
    af(prim);
    adf(prim,ultim,5);
    af(prim);
    sv(prim,ultim,1);
    af(prim);
    sp(prim,ultim,1);
    af(prim);
    adf(prim,ultim,8);
    af(prim);
    return 0;
}
