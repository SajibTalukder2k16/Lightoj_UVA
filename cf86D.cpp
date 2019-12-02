#include<bits/stdc++.h>
using namespace std;
#define mx 200100
#define ll long long
int ara[mx];
ll ans[mx];
int cnt[1000100];
struct node{
    int left,right,index;
}query[mx];
#define block 448
ll answer=0;
bool cmp(node a,node b)
{
    if(a.left/block!=b.left/block)
    {
        return a.left/block <b.left/block;
    }
    return a.right<b.right;
}
void remove(int pos)
{
    int temp=ara[pos];
    ll dummy=(ll)cnt[temp];
    dummy*=dummy;
    dummy*=temp;
    answer-=dummy;
    cnt[temp]--;
    dummy=cnt[temp];
    dummy*=dummy;
    dummy*=(ll)temp;
    answer+=dummy;
}
void add(int pos)
{
    int temp=ara[pos];
    ll dummy=(ll)cnt[temp];
    dummy*=dummy;
    dummy*=temp;
    answer-=dummy;
    cnt[temp]++;
    dummy=cnt[temp];
    dummy*=dummy;
    dummy*=(ll)temp;
    answer+=dummy;
}
int main()
{
    int test,cs;
        int i,n,q;
        scanf("%d%d",&n,&q);
        for(i=1;i<=n;i++)
            scanf("%d",&ara[i]);
        for(i=1;i<=q;i++)
        {
            scanf("%d%d",&query[i].left,&query[i].right);
            query[i].index=i;
        }
        sort(query+1,query+q,cmp);
        int currentleft=1,currentright=1;
        for(i=1;i<=q;i++)
        {
            int left=query[i].left;
            int right=query[i].right;
            while(currentleft<left)
            {
                remove(currentleft);
                currentleft++;
            }
            while(currentleft>left)
            {
                add(currentleft-1);
                currentleft--;
            }
            while(currentright<=right)
            {
                add(currentright);
                currentright++;
            }
            while(currentright>right+1)
            {
                remove(currentright-1);
                currentright--;
            }
            ans[query[i].index]=answer;
        }

        for(i=1;i<=q;i++)
            printf("%lld\n",ans[i]);
}
