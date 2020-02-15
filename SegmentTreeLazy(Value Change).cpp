#include<bits/stdc++.h>
using namespace std;
#define mx 100001
int ara[mx];
struct info{
    long long prop,sum;
}tree[mx*3];
void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].sum=ara[b];
        tree[node].prop=-1;
        return;
    }
    int left = node*2;
    int right = node*2 +1;
    int mid =(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].sum = tree[left].sum+tree[right].sum;
    tree[node].prop=-1;
}
void update(int node,int b,int e,int i,int j,int x,int carry=0)
{
    if(i>e || j<b)
    {
        if(carry!=-1)
        {
            tree[node].sum=(e-b+1)*carry;
            tree[node].prop=carry;
        }
        return;
    }
    if(b>=i && e<=j)
    {
        tree[node].sum=(e-b+1)*x;
        tree[node].prop=x;
        return;
        //return tree[node].sum;
    }
    int left = node*2;
    int right = (node*2)+1;
    int mid = (b+e)/2;
    if(carry!=-1)
        tree[node].prop=carry;
    //if(tree[node].prop==-1)
        //tree[node].prop=carry;
    update(left,b,mid,i,j,x,tree[node].prop);
    update(right,mid+1,e,i,j,x,tree[node].prop);
    tree[node].sum = tree[left].sum + tree[right].sum;
    tree[node].prop=-1;

}
int query(int node,int b,int e,int i,int j,int carry = 0)
{
    if(i>e||j<b)
    {
        /*if(carry!=-1)
        {
            tree[node].sum=(e-b+1)*carry;
            tree[node].prop=carry;
        }*/
        return 0;
    }
    if(b>=i && e<=j)
    {
        if(carry==-1)
            return tree[node].sum;
        else
        {
            //tree[node].sum=carry*(e-b+1);
            //tree[node].prop=carry;
            return carry*(e-b+1);
        }
    }
    //int temp =tree[node].prop;

    int left =node*2;
    int right = node*2 +1;
    int mid =(b+e)/2;
    int temp=tree[node].prop;
    if(carry!=-1)
        temp=carry;

    int p1 =query(left, b, mid, i, j, temp);
    int p2= query(right, mid + 1, e, i, j, temp);
    return p1+p2;
}
int main()
{
   int n=7;
   for(int i=1;i<=n;i++)
        ara[i]=i;
    init(1,1,n);
    query(1,1,n,2,3,-1);
    update(1,1,n,1,4,2,-1);
}
