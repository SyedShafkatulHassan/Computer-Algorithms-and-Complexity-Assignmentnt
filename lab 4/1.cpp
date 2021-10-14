#include <bits/stdc++.h>
using namespace std;
int visit[10000];
int distence[10000];
vector<int>g[10000];
stack<int>s;
void hi(int p)
{
    visit[p]=1;
    if(g[p].size()==0)
    {
        s.push(p);
    }
    else
    {
        vector<int>::iterator ptr;
        ptr=g[p].begin();
        int ans=g[p].size();
        int d=*ptr;
        while(1)
        {
            if(ans==0)
            {
                break;
            }
            if(visit[*ptr]==0)
            {
                hi(*ptr);
            }
            ans--;
        }
        s.push(p);
    }
}
int main()
{
    int node,edge;
    cout<<"Enter total node and total edge: ";
    cin>>node>>edge;
    vector<int>k;
    set<int>s1;
    int arr[1000];
    for(int i=0; i<edge; i++)
    {
        int a,b;
        cin>>a>>b;
        s1.insert(a);
        s1.insert(b);
        g[a].push_back(b);
    }
    int d=0;
    for(int i=0; i<s1.size(); i++)
    {
        if(visit[i]==0)
        {
            hi(i);
        }
    }
    while(1)
    {
        if(s.empty())
        {
            break;
        }
        cout<<s.top()<<" ";
        s.pop();
    }
}
