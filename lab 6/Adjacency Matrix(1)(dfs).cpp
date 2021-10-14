#include<bits/stdc++.h>
using namespace std;
int colum[10000];
int row[10000];
int arr[100][100];
int yo[10][10];
int ans[1000];
int vi[10000];
int main()
{
    int node,edge;
    cout<<"Enter edge and node : ";
    cin>>node>>edge;
    for(int i=1; i<=edge; i++)
    {
        int r,c;
        cin>>r>>c;
        row[i]=r;
        colum[i]=c;
    }
    int a=0;
    for(int i=1; i<=node; i++)
    {
        if(a==edge+1)
        {
            break;
        }
        int r,c;
        r=row[a];
        c=colum[a];
        a++;
        for(int j=1; j<=node; j++)
        {
            arr[r][c]=1;
            arr[c][r]=1;
        }
    }
    stack<int>s;
    s.push(row[1]);
    int ans[1000];
    int p=0;
    vi[row[1]]=1;
    while(1)
    {
        if(s.empty())
        {
            break;
        }
        int tp=s.top();
        ans[p]=tp;
        p++;
        s.pop();
        for(int j=1; j<=node; j++)
        {
            if(arr[j][tp]==1 && vi[j]==0)
            {
                vi[j]=1;
                s.push(j);
            }
        }
    }
    for(int i=0; i<p; i++)
    {
         cout<<ans[i]<<" ";
    }
}
