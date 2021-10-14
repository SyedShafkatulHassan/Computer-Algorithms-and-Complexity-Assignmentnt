#include <bits/stdc++.h>
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
    int  n, arr[1000], k[1000], ami[1000],high,s= -1;
    memset(ami, -1, sizeof ami);
    cout<<"Enter total number of element : ";
    cin >> n;
    cout<<"Enter elements of array : ";
    for(int i = 1; i <= n; i++)
    {
        cin>>arr[i];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            if(arr[j]>=arr[i])
            {
                if(k[j] < k[i] + 1)
                {
                    k[j] = k[i] + 1;
                    if(k[j]>high)
                    {
                        high = k[j];
                        s = j;
                    }
                    ami[j] = i;
                }
            }
        }
    }
    int ar[1000];
    int o=0;
    while(s>0)
    {
        o++;
        ar[o]=arr[s];
        s = ami[s];
    }
    cout<<"Longest Non-Decreaing Subsequence length is: ";
    cout<<o<<endl;
    cout<<"Longest Non-Decreaing Subsequence : ";
    for(int i=o;i>=1;i--)
    {
        cout<<ar[i]<< " ";
    }
}

