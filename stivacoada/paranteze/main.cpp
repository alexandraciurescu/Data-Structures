#include <iostream>
using namespace std;

bool Test(char sir[])
{  char S[256];
   int top=0, i;
   for(i=0; sir[i]!=0; i++)
      if(sir[i]=='(') S[++top]='(';
      else if(top==0) return 0;
           else top--;
   return top==0;
}

int main()
{
   char sir[256];
   int n,i;
   cin>>sir;
   cout<<Test(sir)<<"\n";
   return 0;
}
