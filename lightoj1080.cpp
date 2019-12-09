#include<bits/stdc++.h>
using namespace std;
#define mx 100001
int ara[mx];
struct info{
    long long update_count,sum;
}tree[mx*3];
void init(int node,int b,int e)
{
    if(b==e)
    {
        //cout<<node<<" "<<tree[node]<<endl;
        tree[node].sum=ara[b];
        tree[node].update_count=0;
        //cout<<node<<" "<<tree[node].sum<<endl;
        return;
    }
    int left = node*2;
    int right = node*2 +1;
    int mid =(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].update_count=0;
}
void update(int node,int b,int e,int i,int j,int carry=0)
{
    if(i>e || j<b)
    {
        tree[node].update_count+=carry-1;
        //cout<<i<<" "<<j<<" "<<tree[node].update_count<<endl;
        return;
    }
    if(b>=i && e<=j)
    {
        tree[node].update_count+=carry;
        //cout<<i<<" in range "<<j<<" "<<tree[node].update_count<<endl;
        return;
        //return tree[node].sum;
    }
    int left = node*2;
    int right = (node*2)+1;
    int mid = (b+e)/2;
    tree[node].update_count+=carry;
    update(left,b,mid,i,j,tree[node].update_count);
    update(right,mid+1,e,i,j,tree[node].update_count);
    tree[node].update_count=0;
    return;
}
int answer=-1;
void query(int node,int b,int e,int i,int j,int carry = 0)
{
    if(i>e||j<b)
    {
        return;
    }
    if(b>=i && e<=j)
    {
        carry+=tree[node].update_count;
        if(carry%2==0)
        {
              answer = tree[node].sum;
              return;
        }
        else
        {
            if(tree[node].sum==0)
                answer=1;
            else
                answer=0;
            return;
        }
    }
    int left =node*2;
    int right = node*2 +1;
    int mid =(b+e)/2;
    carry+=tree[node].update_count;
    query(left, b, mid, i, j, carry);
    query(right, mid + 1, e, i, j, carry);
    return;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int tests,cs,i;
    scanf("%d\n",&tests);
    //cin>>tests;
    for(cs=1;cs<=tests;cs++)
    {
        char str[mx];
        scanf("%s\n",str);
        //cout<<str<<endl;
        //cin>>str;
        int n = strlen(str);
        //cout<<"Size: "<<n<<endl;
        for(i=1;i<=n;i++)
            ara[i]=str[i-1]-48;
        init(1,1,n);
        int q;
        scanf("%d\n",&q);
        //cout<<q<<endl;
        printf("Case %d:\n",cs);
        //cin>>q;
        for(i=1;i<=q;i++)
        {
            char ch;
            //cin>>ch;
            scanf("%c\n",&ch);
            if(ch=='I')
            {
                int from,to;
                scanf("%d%d\n",&from,&to);
                //cin>>from>>to;
                update(1,1,n,from,to,1);
            }
            else if(ch=='Q')
            {
                int index;
                scanf("%d\n",&index);
                //cin>>index;
                query(1,1,n,index,index);
                printf("%d\n",answer);
                //cout<<answer<<endl;
            }

        }
    }
}
