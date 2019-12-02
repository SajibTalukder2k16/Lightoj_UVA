#include<bits/stdc++.h>
using namespace std;
#define mx 300001
#define mx2 2000001
int ara[mx];
int cnt[mx2];
int ans[mx];
struct node{
    int left,right,index;
}query[mx2];
#define block 550
int answer=0;
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
    cnt[temp]--;
    if(cnt[temp]==0)
        answer--;
}
void add(int pos)
{
    int temp=ara[pos];
    cnt[temp]++;
    if(cnt[temp]==1)
        answer++;
}
int main()
{
    //freopen("input.txt","r",stdin);
    int test,cs;
        //cout<<"Case "<<cs<<":"<<endl;
        int i,n,q;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&ara[i]);
        scanf("%d",&q);
        for(i=1;i<=q;i++)
        {
            scanf("%d%d",&query[i].left,&query[i].right);
            query[i].index=i;
        }
        sort(query+1,query+q,cmp);
        //for(i=1;i<=q;i++)
           // cout<<query[i].left<<" "<<query[i].right<<endl;
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
            printf("%d\n",ans[i]);
            //cout<<ans[i]<<endl;
}
