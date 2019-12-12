#include<bits/stdc++.h>
using namespace std;
#define mx 100001
int ara[mx];
struct info{
    long long prop,cnt1,cnt2,cnt3;
}tree[mx*3];
void init(int node,int b,int e)
{
    if(b==e)
    {
        int temp = ara[b]%3;
        if(temp==0)
        {
            tree[node].cnt1=0;
            tree[node].cnt2=0;
            tree[node].cnt3=1;
        }
        else if(temp==1)
        {
            tree[node].cnt1=1;
            tree[node].cnt2=0;
            tree[node].cnt3=0;
        }
        else
        {
            tree[node].cnt1=0;
            tree[node].cnt2=1;
            tree[node].cnt3=0;
        }
        tree[node].prop=0;
        return;
    }
    int left = node*2;
    int right = node*2 +1;
    int mid =(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].cnt1 = tree[left].cnt1+tree[right].cnt1;
    tree[node].cnt2 = tree[left].cnt2+tree[right].cnt2;
    tree[node].cnt3 = tree[left].cnt3+tree[right].cnt3;
    tree[node].prop=0;
    return ;
}
void update(int node,int b,int e,int i,int j,int carryupdate)
{
    if(i>e || j<b)
    {
        --carryupdate;
        carryupdate%=3;
        for(int p=0;p<carryupdate;p++)
        {
            int tempcnt1=tree[node].cnt1;
            int tempcnt2=tree[node].cnt2;
            int tempcnt3=tree[node].cnt3;
            tree[node].cnt1=tempcnt3;
            tree[node].cnt2=tempcnt1;
            tree[node].cnt3=tempcnt2;
        }
        tree[node].prop+=carryupdate;
        return;
    }
    if(b>=i && e<=j)
    {
        carryupdate%=3;
        for(int p=0;p<carryupdate;p++)
        {
            int tempcnt1=tree[node].cnt1;
            int tempcnt2=tree[node].cnt2;
            int tempcnt3=tree[node].cnt3;
            tree[node].cnt1=tempcnt3;
            tree[node].cnt2=tempcnt1;
            tree[node].cnt3=tempcnt2;
        }
        tree[node].prop+=carryupdate;
        return;
    }
    tree[node].prop+=carryupdate;
    int left = node*2;
    int right = (node*2)+1;
    int mid = (b+e)/2;
    update(left,b,mid,i,j,tree[node].prop);
    update(right,mid+1,e,i,j,tree[node].prop);
    tree[node].cnt1 = tree[left].cnt1+tree[right].cnt1;
    tree[node].cnt2 = tree[left].cnt2+tree[right].cnt2;
    tree[node].cnt3 = tree[left].cnt3+tree[right].cnt3;
    tree[node].prop=0;
    return ;

}
int query(int node,int b,int e,int i,int j,int carry = 0)
{
    if(i>e||j<b)
        return 0;
    if(b>=i && e<=j)
    {
        carry%=3;
        int tempcnt1=tree[node].cnt1;
        int tempcnt2=tree[node].cnt2;
        int tempcnt3=tree[node].cnt3;
        int temp1=tree[node].cnt1;
        int temp2=tree[node].cnt2;
        int temp3=tree[node].cnt3;
        for(int p=0;p<carry;p++)
        {
            tree[node].cnt1=tempcnt3;
            tree[node].cnt2=tempcnt1;
            tree[node].cnt3=tempcnt2;
            tempcnt1=tree[node].cnt1;
            tempcnt2=tree[node].cnt2;
            tempcnt3=tree[node].cnt3;
        }
        int res =tree[node].cnt3;
        tree[node].cnt1=temp1;
        tree[node].cnt2=temp2;
        tree[node].cnt3=temp3;
        return res;
    }
    int left =node*2;
    int right = node*2 +1;
    int mid =(b+e)/2;
    int p1 =query(left, b, mid, i, j, carry + tree[node].prop);
    int p2= query(right, mid + 1, e, i, j, carry + tree[node].prop);
    return p1+p2;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int cs, tests;
    scanf("%d",&tests);
    for(cs=1;cs<=tests;cs++)
    {
        int n,q;
        //cin>>n>>q;
        scanf("%d%d",&n,&q);
        //cout<<n<<" "<<q<<endl;
        for(int p=1;p<=n;p++)
            ara[p]=0;
        init(1,1,n);
        int chk,i,j;
        printf("Case %d:\n",cs);
        int k;
        for(k=1;k<=q;k++)
        {
            scanf("%d%d%d",&chk,&i,&j);
            //cout<<chk<<" "<<i<<" "<<j<<endl;
            if(chk==0)
            {
                update(1,1,n,i+1,j+1,1);
            }
            else
            {
                printf("%d\n",query(1,1,n,i+1,j+1));//<<endl;
            }
        }
    }
}
