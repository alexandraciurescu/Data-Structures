#include <iostream>
using namespace std;


struct nod
{ int info;
  nod *st,*dr;
};

nod* Creare()
{  int x;
   cin>>x;
   if(x==0)return NULL;
   else {nod *p=new nod;
         p->info=x;
         p->st=Creare();
         p->dr=Creare();
         return p;
        }
}

void RSD(nod *r, int nivel, int k)
{ if(r)
    {  if (nivel==k) cout<<r->info<<" ";
       if(nivel<k)
          { RSD(r->st,nivel+1,k);
            RSD(r->dr,nivel+1,k);
          }
    }

}

int main()
{   nod *rad; int k;
    cout<<"Arborele: ";  /// 67 51 18 0 0 24 0 0 48 0 11 0 0
    rad=Creare();
    cout<<"k="; cin>>k;
    RSD(rad,0,k);
    return 0;
}
