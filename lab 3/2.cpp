#include <bits/stdc++.h>
using namespace std;
int A[1000],B[1000];
#define pb push_back;
int fib1[10000]= {-1};
int p=0;
string d;
int dp[1000][1000];
string s,s1;
int n,m;
int lsc(){
    int a,b;
    int dp[n+1][m+1];
    for(a=0; a<=m; a++)
    {
        dp[0][a]=0;
    }
    for(a=0; a<=n; a++)
    {
        dp[a][0]=0;
    }
    for(a=1; a<=n; a++)
    {
        for(b=1; b<=m; b++)
        {
            if(s[a-1]==s1[b-1])
            {
                dp[a][b]=1+dp[a-1][b-1];
            }
            else
            {
                dp[a][b]=max(dp[a-1][b],dp[a][b-1]);
            }
        }
    }
    a=n,b=m;
    string ans="";
    while(a!=0 && b!=0)
    {
        if(s[a-1]==s1[b-1])
        {
            ans+=s[a-1],a--,b--;
        }
        else
        {
            if(dp[a-1][b]>dp[a][b-1])
            {
                a--;
            }
            else
            {
                b--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
    cout << dp[n][m] << endl;
}
int main()
{
    cin>>s>>s1;
    n=s.size();
    m=s1.size();
    lsc();
}

