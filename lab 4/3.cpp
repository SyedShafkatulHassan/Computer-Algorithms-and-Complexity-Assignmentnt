#include <bits/stdc++.h>
using namespace std;
vector<int>g[100],n ;
int visited[100];
int t[100],low[100],d = 0;
set<int>vq;
void ar(int q, int p)
{
    visited[q] = 1 ;
    t[q] = low[q] = d++ ;
    int c=0 ;
    for(auto i : g[q])
    {
        if(visited[i]==0)
        {
            c++;
            ar(i, q) ;
            low[q] = min(low[q], low[i]) ;
            if(low[i] >= t[q] && !(p == -1 && c < 2))
            {
                vq.insert(q);
            }
        }
        else if(i!=p)
        {
            low[q] = min(low[q], t[i]) ;
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=1; i<=e; i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i = 1 ; i<= n ; i++)
    {
        if(visited[i]==0)
        {
            d = 0 ;
            ar(i, -1) ;
        }
    }
    for (auto i = vq.begin(); i != vq.end(); i++)
    {
        cout << *i << " ";
    }
}
