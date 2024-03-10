#include <iostream>
#define N 100000
using namespace std;

int a[N];

int main()
{   int n,i,j;
    int cand,vot;
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];

    /// desemnam o valoare care are sanse sa fie element majoritar
    /// presupunem ca prima valoare are sanse sa fie majoritar (are deja 1 vot)
    cand=a[1]; vot=1;
    for(i=2;i<=n;i++)
        if(a[i]==cand) vot++; /// cand gasim o valoare egala ii cresc sansele (marim numarul de voturi)
        else if(vot>0) vot--; /// cand gasim o valoare diferita ii scadem din voturi daca mai are
             else {cand=a[i]; vot=1;} /// daca nu  mai are voturi vom schimba candidatul

    /// verificam daca elementul gasit chiar este majoritar (are cel putin n/2+1 aparitii)
    vot=0;
    for(i=1;i<=n;i++)
        if(a[i]==cand) vot++;

    if(vot>n/2) cout<<"DA "<<cand;
    else cout<<"NU";


    return 0;
}
