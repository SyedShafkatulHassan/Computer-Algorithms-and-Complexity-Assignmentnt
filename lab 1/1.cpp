#include <bits/stdc++.h>
using namespace std;
int A[1000],B[1000];
#define pb push_back;
int fib1[10000]= {-1};
int p=0;
int fib(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }
    else if(fib1[n]<0)
    {
        return fib1[n];
    }
    else
    {
        return fib1[n]=fib1[n-1]+fib1[n-2];
    }
}
int main()
{
    fib1[0]=0;
    fib1[1]=1;
    int n,c,d=0;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        cout<<fib(a)<<endl;
    }
}


