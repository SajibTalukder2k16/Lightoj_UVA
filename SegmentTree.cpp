#include<bits/stdc++.h>
using namespace std;
#define mx 100001
int ara[mx];
int tree[mx*3];
void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=ara[b];
        return;
    }
    int left = node*2;
    int right = node*2 +1;
    int mid =(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node] = tree[left]+tree[right];
}
int query(int node,int b,int e,int i,int j)
{
    if(i>e ||j<b)
        return 0;
    if(b>=i&&e<=j)
        return tree[node];
    int left = 2*node;
    int right = 2*node +1;
    int mid = (b+e)/2;
    int q1 = query(left,b,mid,i,j);
    int q2 = query(right,mid+1,e,i,j);
    return q1+q2;
}
void update(int node,int b,int e,int i,int newvalue)
{
    if(i>e || i<b)
        return;
    if(b>=i && e<=i)
    {
        tree[node] = newvalue;
        return ;
    }
    int left = 2*node;
    int right = 2*node+1;
    int mid = (b+e)/2;
    update(left,b,mid,i,newvalue);
    update(right,mid+1,e,i,newvalue);
    tree[node]=tree[left]+tree[right];
}
int main()
{
    int n;
    cin>>n;
    int i;
    for(i=1;i<=n;i++)
    {
        cin>>ara[i];
    }
    init(1,1,n);
    int r1,r2;
    cin>>r1>>r2;
    cout<<query(1,1,n,r1,r2);
}
