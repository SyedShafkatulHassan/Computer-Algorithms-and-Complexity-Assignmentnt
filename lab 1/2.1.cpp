#include <bits/stdc++.h>
using namespace std;
int A[1000],B[1000];
#define pb push_back;
int p=0;
int pro[1000];
int weg[1000];
int dp[1000][1000];
int np(int weg[],int pro[],int c,int n)
{
    if(n==0 || c==0)
    {
        return 0;
    }
    if(dp[c][n]!=-1)
    {
        return dp[c][n];
    }
    else if(weg[n-1]>c)
    {
        return dp[c][n]=np(weg,pro,c,n-1);
    }
    else if(weg[n-1]<=c)
    {
        return dp[c][n]=max(pro[n-1]+np(weg,pro,c-weg[n-1],n-1),np(weg,pro,c,n-1));
    }
}
int main()
{
    int n,c;
    cout<<"Enter the weight of the bag : ";
    cin>>c;
    cout<<"Enter total elements : ";
    cin>>n;
    cout<<"Enter total elements of profit : ";
    memset(dp,-1,sizeof(dp));
    for(int a=0; a<n; a++)
    {
        cin>>pro[a];
    }
    cout<<"Enter total weights : ";
    for(int a=0; a<n; a++)
    {
        cin>>weg[a];
    }
    cout<<np(weg,pro,c,n);
}

