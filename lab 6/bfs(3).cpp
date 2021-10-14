#include<bits/stdc++.h>
using namespace std;
int visit[10000];
int distence[10000];
int main()
{
    int node,edge;
    cout<<"Enter total node and edge : ";
    cin>>node>>edge;
    vector<int>bfs[10000];
    for(int i=1; i<=edge; i++)
    {
        int a,b;
        cin>>a>>b;
        bfs[a].push_back(b);
        bfs[b].push_back(a);
    }
    queue<int>q;
    cout<<"Enter root node : ";
    int p;
    cin>>p;
    visit[p]=1;
    distence[p]=0;
    q.push(p);
    while(1)
    {
        if(q.empty())
        {
            break;
        }
        int tp=0;
        tp=q.front();
        q.pop();
        for(int i=0; i<bfs[tp].size(); i++)
        {
            if(visit[bfs[tp][i]]==0)
            {
                visit[bfs[tp][i]]=1;
                distence[bfs[tp][i]]=distence[tp]+1;
                q.push(bfs[tp][i]);
            }
        }
    }
    int w;
    cout<<"Enter the destination : ";
    cin>>w;
    cout<<distence[w];
}
