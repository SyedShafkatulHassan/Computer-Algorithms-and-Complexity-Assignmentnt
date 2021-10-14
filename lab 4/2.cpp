#include<bits/stdc++.h>
using namespace std;
int mx=1000;
vector<int>v[1000],ans;
int in[1000];
int vis[1000][1000];
void dfs(int a,int b)
{
    vis[b][a]=1;
    for(auto c: v[a])
    {
        if(vis[a][c]==0)
        {
            in[c]++;
            dfs(c,a);
        }
    }
}
int main()
{
    int n,e;
    cin >> n >> e;
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
    }
    for(int i=1;i<=n;i++)
    {
        dfs(i,mx);
    }
    queue<int>q;
    int o;
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0)
        {
            q.push(i);
        }
    }
    while(1)
    {
        if(q.empty())
        {
            break;
        }
        o=q.front();
        q.pop();
        ans.push_back(o);
        for(auto c: v[o])
        {
            in[c]--;
            if(in[c]==0)
            {
                q.push(c);
            }
        }
    }
    for(int i=0;i<ans.size();i++)
    {
        cout << ans[i] << " ";
    }
}
