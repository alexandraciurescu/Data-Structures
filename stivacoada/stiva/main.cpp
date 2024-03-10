#include <iostream>

using namespace std;

int S[10002],top;

bool Empty(int S[], int top)
{ return top==0;
}

void Push(int S[], int &top, int x)
{ S[top++]=x;
}

void Pop(int S[], int &top)
{ if(!Empty(S,top))
     top--;
}

int Peek(int S[], int top)
{ return S[top-1];
}

void Show(int S[], int top)
{  for(int i=0; i<top; i++)
        cout<<S[i]<<" ";
    cout<<"\n";
}

int main()
{
    int x,i,n;
    cin>>n;
    for(i=0; i<n; i++)
       { cin>>x;
         Push(S,top,x);
       }
    Show(S,top);
    Pop(S,top);
    Show(S,top);
    cout<<Peek(S,top);
    return 0;
}
