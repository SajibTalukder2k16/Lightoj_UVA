#include<bits/stdc++.h>
using namespace std;
struct info
{
    int max_prefix;
    int max_suffix;
    int max_sum;
    int total_sum;
};
#define mx 500001
int ara[mx];
info tree[mx*4];
void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].max_prefix=ara[b];
        tree[node].max_suffix=ara[b];
        tree[node].total_sum=ara[b];
        tree[node].max_sum=ara[b];
        return;
    }
    int left = node*2;
    int right = node*2 +1;
    int mid =(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].total_sum = tree[left].total_sum + tree[right].total_sum;
    tree[node].max_sum = max(tree[left].max_suffix+tree[right].max_prefix,max(tree[left].max_sum,tree[right].max_sum));
    tree[node].max_prefix = max(tree[left].max_prefix,tree[left].total_sum+tree[right].max_prefix);
    tree[node].max_suffix = max(tree[right].max_suffix,tree[right].total_sum+tree[left].max_suffix);
}
info query(int node,int b,int e,int i,int j)
{
    if(b>=i&&e<=j)
        return tree[node];
    int left = 2*node;
    int right = 2*node +1;
    int mid = (b+e)/2;
    if(mid>=j)
        return query(left,b,mid,i,j);
    else if(mid<i)
        return query(right,mid+1,e,i,j);
    else
    {
        info q1 = query(left,b,mid,i,j);
        info q2 = query(right,mid+1,e,i,j);
        info res;
        res.total_sum=q1.total_sum+q2.total_sum;
        res.max_sum = max(q1.max_suffix+q2.max_prefix,max(q1.max_sum,q2.max_sum));
        res.max_prefix = max(q1.max_prefix,q1.total_sum+q2.max_prefix);
        res.max_suffix = max(q2.max_suffix,q2.total_sum+q1.max_suffix);
        return res;
    }
}
void update(int node,int b,int e,int i,int newvalue)
{
    if(i>e || i<b)
        return;
    if(b>=i && e<=i)
    {
        //cout<<"Value updated: "<<endl;
        tree[node].total_sum = newvalue;
        tree[node].max_prefix = newvalue;
        tree[node].max_suffix = newvalue;
        tree[node].max_sum = newvalue;
        //cout<<newvalue<<endl;
        return;
    }
    int left = 2*node;
    int right = 2*node+1;
    int mid = (b+e)/2;
    update(left,b,mid,i,newvalue);
    update(right,mid+1,e,i,newvalue);
    tree[node].total_sum = tree[left].total_sum + tree[right].total_sum;
    tree[node].max_sum = max(tree[left].max_suffix+tree[right].max_prefix,max(tree[left].max_sum,tree[right].max_sum));
    tree[node].max_prefix = max(tree[left].max_prefix,tree[left].total_sum+tree[right].max_prefix);
    tree[node].max_suffix = max(tree[right].max_suffix,tree[right].total_sum+tree[left].max_suffix);
    return;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>ara[i];
    init(1,1,n);
    int q,chk,r1,r2;
    cin>>q;
    while(q--)
    {
        cin>>chk>>r1>>r2;
        if(chk==0)
            update(1,1,n,r1,r2);
        else
            cout<<query(1,1,n,r1,r2).max_sum<<endl;;
    }
}
