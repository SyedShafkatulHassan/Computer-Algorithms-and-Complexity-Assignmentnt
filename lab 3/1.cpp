#include <bits/stdc++.h>
using namespace std;
int A[1000],B[1000];
#define pb push_back;
int fib1[10000]= {-1};
int p=0;
string d[1000][1000];
int dp[1000][1000];
string s,s1;
int i,j;
int dkl=0;
int lcs(int i,int j)
{
    if(i>=s.size() || j>=s1.size())
    {
        return 0;
    }
    else if(~dp[i][j])
    {
        return dp[i][j];
    }
    else if(s[i]==s1[j])
    {
        return dp[i][j]=1+lcs(i+1,j+1);
    }
    else
    {
        return max(lcs(i+1,j),lcs(i,j+1));
    }
}
void Print_lcs()
{
    int a=0,b=0;
    string ans="";
    while(a<s.size() && b<s1.size())
    {
        if(s[a]==s1[b])
        {
                dkl++;
            ans+=s[a],a++,b++;
        }
        else
        {

            if(dp[a+1][b]>dp[a][b+1])
            {
                a++;
            }
            else
            {
                b++;
            }
        }
    }
    cout<<dkl<<endl;
    cout << ans << endl;
}
int main()
{
    memset(dp, -1, sizeof dp);
    cin>>s>>s1;
    int l1,l2;
    l1=s.size();
    l2=s1.size();
    lcs(0,0);
    Print_lcs();
}
