#include<bits/stdc++.h>
using namespace std;
struct info{
    int minvalue;
    int idx;
};
#define mx 30001
int ara[mx];
info tree[mx*3];
void min_range_init(int node,int b,int e)
{

    if(b==e)
    {
        tree[node].minvalue=ara[b];
        tree[node].idx=b;
        return;
    }
    int left = node*2;
    int right = node*2 +1;
    int mid =(b+e)/2;
    min_range_init(left,b,mid);
    min_range_init(right,mid+1,e);
    if(tree[left].minvalue<=tree[right].minvalue)
    {
        tree[node].minvalue=tree[left].minvalue;
        tree[node].idx=tree[left].idx;
    }
    else
    {
        tree[node].minvalue = tree[right].minvalue;
        tree[node].idx = tree[right].idx;
    }
    return;
}
info tt;
info range_min_query(int node,int b,int e,int i,int j)
{

    if(i>e ||j<b)
    {
        return tt;
    }
    if(b>=i&&e<=j)
        return tree[node];
    int left = 2*node;
    int right = 2*node +1;
    int mid = (b+e)/2;
    info q1 = range_min_query(left,b,mid,i,j);
    info q2 = range_min_query(right,mid+1,e,i,j);
    if(q1.minvalue<=q2.minvalue)
    {
        return q1;
    }
    else
        return q2;
}
int max_histrogram(int b,int e,int i,int j)
{
    info temp;
    temp = range_min_query(1,b,e,i,j);
    int index = temp.idx;
    //cout<<i<<" "<<j<<" "<<temp.idx<<endl;
    if(i==j)
        return ara[i];
    if(i>j)
        return 0;
    int area1 = temp.minvalue*(j-i+1);
    int area2,area3;
    area2 = max_histrogram(b,e,i,temp.idx-1);
    area3 = max_histrogram(b,e,temp.idx+1,j);
    return max(area1,max(area2,area3));
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    tt.minvalue=INT_MAX;
    tt.idx=0;
    int test,cs;
    scanf("%d",&test);
    for(cs=1;cs<=test;cs++)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&ara[i]);
        }
        min_range_init(1,1,n);
        int ans = max_histrogram(1,n,1,n);
        printf("Case %d: %d\n",cs,ans);
    }
}
