#include<bits/stdc++.h>
using namespace std;
#define mx 150010
struct info
{
    int value;
    int no_of_node;
};
info tree[mx*4];
int query(int node,int b,int e,int pos)
{
    tree[node].no_of_node--;
    if(b==e)
    {
        return tree[node].value;
    }
    int left = 2*node;
    int right = 2*node +1;
    int mid = (b+e)/2;
    if(tree[left].no_of_node>=pos)
    {
        query(left,b,mid,pos);
    }
    else
    {
        query(right,mid+1,e,pos-tree[left].no_of_node);
    }
}
void update(int node,int b,int e,int i,int newvalue)
{
    if(i==b && b==e)
    {
        tree[node].value = newvalue;
        tree[node].no_of_node = 1;
        return ;
    }
    int left = 2*node;
    int right = 2*node+1;
    int mid = (b+e)/2;
    if(i<=mid)
        update(left,b,mid,i,newvalue);
    else
        update(right,mid+1,e,i,newvalue);
    tree[node].no_of_node = tree[left].no_of_node + tree[right].no_of_node;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int test;
    scanf("%d",&test);
    for(int cs=1;cs<=test;cs++)
    {
        int n,q;
        scanf("%d%d",&n,&q);
        int num;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num);
            update(1,1,n+q,i+1,num);
        }
        char ch;
        int k;
        int cur_index=n+1;
        printf("Case %d:\n",cs);
        for(int i=0;i<q;i++)
        {
            scanf("\n%c%d",&ch,&k);
            if(ch=='a')
            {
                update(1,1,n+q,cur_index,k);
                cur_index++;
            }
            else if(ch=='c')
            {
                if(tree[1].no_of_node<k)
                {
                    printf("none\n");
                }
                else
                {
                    printf("%d\n",query(1,1,n+q,k));
                }
            }
        }
        memset(tree,0,sizeof tree);
    }
}
