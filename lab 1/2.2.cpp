#include <bits/stdc++.h>
using namespace std;
int A[1000],B[1000];
#define pb push_back;
int p=0;
int pro[1000];
int weg[1000];
int dp[1000][1000];
int main()
{
    int w,n;
    cout<<"Enter total weight of the bag : ";
    cin>>w;
    cout<<"Enter total elements : ";
    cin>>n;
    int weight[1000];
    int value[1000];
    int dp[n+1][w+1];
    cout<<"Enter total elements of profit : ";
    memset(dp,-1,sizeof(dp));
    for(int a=0; a<n; a++)
    {
        cin>>value[a];
    }
    cout<<"Enter total weights : ";
    for(int a=0; a<n; a++)
    {
        cin>>weight[a];
    }
    for(int a=0; a<=n; a++)
    {
        dp[a][0]=0;
    }
    for(int a=0; a<=w; a++)
    {
        dp[0][a]=0;
    }
    for(int a=1; a<=n; a++)
    {
        for(int b=1; b<=w; b++)
        {
            if(weight[a-1]<=b)
            {
                dp[a][b]=max(dp[a-1][b],value[a-1]+dp[a-1][b-weight[a-1]]);
            }
            else
            {
                dp[a][b]=dp[a-1][b];
            }
        }
    }
    cout << dp[n][w] << endl;
}

