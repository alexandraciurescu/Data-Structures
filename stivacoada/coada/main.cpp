#include <iostream>

using namespace std;

int Q[10005],st=1,dr=0;

bool Empty(int Q[], int st, int dr)
{ return st>dr; //1 daca e vida
}

void Push(int Q[], int &st, int &dr,int x)
{ Q[++dr]=x;
}

void Pop(int Q[], int &st, int &dr)
{ if(!Empty(Q,st,dr))
     st++;
}

int Peek(int Q[], int st, int dr)
{ return Q[st];
}

void Show(int Q[], int st, int dr)
{  for(int i=st; i<=dr; i++)
        cout<<Q[i]<<" ";
    cout<<"\n";
}

int main()
{
    int n,i,x;
    cin>>n;
    for(i=1; i<=n; i++)
      {cin>>x;
       Push(Q,st,dr,x);
      }
    Show(Q,st,dr);
    Pop(Q,st,dr);
    Show(Q,st,dr);
    cout<<Peek(Q,st,dr);
    return 0;
}
