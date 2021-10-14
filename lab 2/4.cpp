#include<bits/stdc++.h>
using namespace std;
int A[1000],B[1000];
#define pb push_back;
int fib1[10000]= {-1};
int p=0;
string d;
int dp[1000][1000];
string s1,s2;
int a[1000];
int sizee=1;
int binary_sarch(int n,int arr[])
{
    int left=-1;
    int right=sizee-2;
    int mid=0;
    while(left<=right)
    {
        mid=(left+(right-left)/2);
        if(arr[a[mid]]==n)
        {
            return sizee;
        }
        if(arr[a[mid]]<n)
        {
            left=mid+1;
        }
        if(arr[a[mid]]>n)
        {
            right=mid-1;
        }
    }
}
int main()
{
    int n;
    cout<<"Enter total number of element : ";
    cin>>n;
    int arr[10000];
    cout<<"Enter elements of array : ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    vector<int>shafkat;
    shafkat.push_back(arr[0]);
    for(int i=0; i<n; i++)
    {
        if(shafkat.back()>=arr[i])
        {
            int d=lower_bound(shafkat.begin(),shafkat.end(),arr[i])-shafkat.begin();
            shafkat[d]=arr[i];

        }
        else
        {
            shafkat.push_back(arr[i]);
        }
    }
    cout<<"LIS length : ";
    cout<<shafkat.size()<<endl;
    int a1[10000];
    memset(a, -1, sizeof a);
    memset(a1, -1, sizeof a1);
    for(int i=0; i<n; i++)
    {
        if (arr[i] < arr[a[0]])
        {
            a[0] = i;
        }
        else if (arr[i] > arr[a[sizee - 1]])
        {
            a1[i] = a[sizee - 1];
            a[sizee++] = i;
        }
        else
        {
            int o=binary_sarch(arr[i],arr);
            a[o] = i;
            a1[i] = a[o - 1];
        }
    }
    int hassan[1000];
    int q=0;
    for (int i = a[sizee-1]; i >=0; i =a1[i])
    {
        hassan[q]= arr[i];
        q++;
    }
    cout<<"LIS: ";
    for(int i=q-1;i>=0;i--)
    {
        cout<<hassan[i]<<" ";
    }
}
