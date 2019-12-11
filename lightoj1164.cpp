#include<bits/stdc++.h>
using namespace std;
#define mx 500001
long long ara[mx];
struct info{
    long long prop,sum;
}tree[mx*3];
void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].sum=0;
        tree[node].prop=0;
        return;
    }
    int left = node*2;
    int right = node*2 +1;
    int mid =(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].sum = tree[left].sum+tree[right].sum;
    tree[node].prop= 0;
}
void update(int node,int b,int e,int i,int j,int x)
{
    if(i>e || j<b)
        return;
    if(b>=i && e<=j)
    {
        long long t=(long long)(e-b+1);
        long long temp = (long long)(t*x);
        tree[node].sum=(long long)(tree[node].sum+temp);
        tree[node].prop= (long long)(tree[node].prop+x);
        return;
        //return tree[node].sum;
    }
    int left = node*2;
    int right = (node*2)+1;
    int mid = (b+e)/2;
    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);
    long long temp = (long long)((long long)tree[node].prop*(long long)(e-b+1));
    tree[node].sum = tree[left].sum + tree[right].sum + temp;

}
long long query(int node,int b,int e,int i,int j,int carry = 0)
{
    if(i>e||j<b)
        return 0;
    if(b>=i && e<=j)
    {
        long long temp = (long long)((long long)carry*(long long)(e-b+1));
        temp+=tree[node].sum;
        return temp;
    }
    int left =node*2;
    int right = node*2 +1;
    int mid =(b+e)/2;
    long long p1 =query(left, b, mid, i, j, carry + tree[node].prop);
    long long p2= query(right, mid + 1, e, i, j, carry + tree[node].prop);
    return p1+p2;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int tests,cs;
    scanf("%d",&tests);
    for(cs=1;cs<=tests;cs++)
    {
        int n,q;
        //cin>>n>>q;
        scanf("%d%d",&n,&q);
        printf("Case %d:\n",cs);
        init(1,1,n);
        for(int i=1;i<=q;i++)
        {
            int chk;
            scanf("%d",&chk);
            if(chk==0)
            {
                int x,y,v;
                scanf("%d%d%d",&x,&y,&v);
                update(1,1,n,x+1,y+1,v);
            }
            else if(chk==1)
            {
                int x,y;
                scanf("%d%d",&x,&y);
                printf("%lld\n",query(1,1,n,x+1,y+1));
            }
        }

    }
}
