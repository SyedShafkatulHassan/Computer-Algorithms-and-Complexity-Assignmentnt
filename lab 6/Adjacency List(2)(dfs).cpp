#include<bits/stdc++.h>
using namespace std;
int visit[10000];
int distence[10000];
int main()
{
    int node,edge;
    cout<<"Enter total node and total edge: ";
    cin>>node>>edge;
    vector<int>g[10000];
    for(int i=0; i<edge; i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    stack<int>s;
    int p;
    cout<<"Enter source node : ";
    cin>>p;
    visit[p]=1;
    s.push(p);
    vector<int>v;
    while(1)
    {
        if(s.empty())
        {
            break;
        }
        int tp=s.top();
        v.push_back(s.top());
        s.pop();
        for(auto it:g[tp])
        {
            if(visit[it]==0)
            {
                visit[it]=1;
                s.push(it);
            }
        }
    }
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}
