#include<bits/stdc++.h>
using namespace std;
int A[1000],B[1000];
#define pb push_back;
int fib1[10000]= {-1};
int p=0;
string d;
int dp[1000][1000];
string s1,s2;
int main()
{
    int n,m;
    cout<<"Enter total coin and total amount : ";
    cin>>n>>m;
    int coin[n];
    cout<<"Enter coins : ";
    for(int i=0; i<n; i++)
    {
        cin>>coin[i];
    }
    int coins[n+1][m+1];
    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<m+1; j++)
        {
            if((i==0 && j==0) || j==0)
            {
                coins[i][j]=0;
            }
            else if(i==0)
            {
                coins[i][j]= INT_MAX-1;
            }
            else if(j>=coin[i-1])
            {
                coins[i][j]= min(coins[i-1][j],1+ coins[i][j-coin[i-1]]);
            }
            else
            {
                coins[i][j]=coins[i-1][j];
            }
        }
    }

    int arr[1000];
    int o=0;
    while(n>0 && m>0)
    {
        if(coins[n][m] == coins[n-1][m])
        {
            n--;
        }
        else
        {
            arr[o]=coin[n-1];
            o++;
            m = m - coin[n-1];
        }
    }
    cout<<"ans : ";
    for(int i=0; i<o; i++)
    {
        cout<<arr[i]<<" ";
    }

}
