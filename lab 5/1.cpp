#include <bits/stdc++.h>
using namespace std;
int A[1000],B[1000];
int main()
{
    int m;
    int l;
    cout<<"Enter total weight:";
    cin>>l;
    cout<<"Enter total element:";
    cin>>m;
    cout<<"Enter all profits:";
    vector<float>b;
    for(int i=0;i<m;i++)
    {
        int shafkat;
        cin>>shafkat;
        b.push_back(shafkat);
    }
    cout<<"Enter all weights:";
    vector<float>c;
    for(int i=0;i<m;i++)
    {
        int shafkat;
        cin>>shafkat;
        c.push_back(shafkat);
    }
    vector<float>d;
    for(int i=0;i<m;i++)
    {
        float hridoy=0;
        hridoy=b[i]/c[i];
        d.push_back(hridoy);
    }
    float arr[m]={};
    int g=0,h=0,n=0,f=1;
    for(int w=0;w<m;w++)
    {
        float maxx=0;
        int k=0;
        for(int i=0;i<m;i++)
        {
             if(d[i]>maxx)
             {
                 maxx=d[i];
                 k=i;
             }
        }
        float n=0;
        for(int i=0;i<c[k];i++)
        {
            if(f<=l)
            {
                f++;
                n++;
            }
            else
            {
                break;
            }
        }
        arr[k]=n*d[k];
        d[k]=0;
    }
    float y=0;
    for(int i=0;i<m;i++)
    {
        y=y+arr[i];
    }
    cout<<y<<endl;
}
