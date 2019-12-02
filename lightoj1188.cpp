#include<bits/stdc++.h>
using namespace std;
#define mx 100001
int ara[mx];
int cnt[mx];
int ans[mx];
struct node{
    int left,right,index;
}query[mx];
#define block 316
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
    scanf("%d",&test);
    for(cs=1;cs<=test;cs++)
    {
        //cout<<"Case "<<cs<<":"<<endl;
        printf("Case %d:\n",cs);
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
        memset(ans,0,sizeof ans);
        memset(cnt,0,sizeof cnt);
        answer=0;
    }
}

/*#include<bits/stdc++.h>
using namespace std;
#define mx 100001
#define pr pair<map<int,bool>,vector<int>>
int ara[mx];
struct info{
    long long sum;
    map<int,bool>mp;
    vector<int>vec;
}tree[mx*3];
void init(int node,int b,int e)
{
    map<int,bool>mpleft,mpright;
    vector<int>vecleft,vecright;
    if(b==e)
    {
        tree[node].sum=1;
        tree[node].mp[ara[b]]=true;
        tree[node].vec.push_back(ara[b]);
        return ;
    }
    int left = node*2;
    int right = node*2 +1;
    int mid =(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    mpleft=tree[left].mp;
    mpright=tree[right].mp;
    vecleft=tree[left].vec;
    vecright=tree[right].vec;
    tree[node].vec=vecleft;
    tree[node].mp=mpleft;
    int sz=vecright.size();
    for(int i=0;i<sz;i++)
    {
        int num =vecright[i];
        if(mpleft[num]==false)
        {
            tree[node].mp[num]=true;
            tree[node].vec.push_back(num);
        }
    }
    tree[node].sum = tree[node].vec.size();
}
pr query(int node,int b,int e,int i,int j)
{
    pr temp;
    if(i>e||j<b)
    {
        return temp;
    }
    if(b>=i&&e<=j)
        return make_pair(tree[node].mp,tree[node].vec);
    int left = 2*node;
    int right =2*node+1;
    int mid=(b+e)/2;
    pr q1 = query(left,b,mid,i,j);
    pr q2 =query(right,mid+1,e,i,j);
    map<int,bool>mp,mpleft,mpright;
    vector<int>vec,vecleft,vecright;
    mpleft=q1.first;
    mpright=q2.first;
    vecleft=q1.second;
    vecright=q2.second;
    vec=vecleft;
    mp=mpleft;
    int sz=vecright.size();
    for(int i=0;i<sz;i++)
    {
        int num =vecright[i];
        if(mpleft[num]==false)
        {
            mp[num]=true;
            vec.push_back(num);
        }
    }
    return make_pair(mp,vec);

}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int test,cs;
    //cin>>test;
    scanf("%d",&test);
    for(cs=1;cs<=test;cs++)
    {
    int n,q;
    scanf("%d%d",&n,&q);
    //cin>>n>>q;
    int i;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&ara[i]);
        //cin>>ara[i];
    }
    init(1,1,n);
    //for(i=1;i<=13;i++)
        //cout<<tree[i].sum<<"\t";
    //cout<<endl;
    printf("Case %d:\n",cs);
    //cout<<"Case :"<<cs<<endl;
    for(i=0;i<q;i++)
    {
        int q1,q2;
        scanf("%d%d",&q1,&q2);
        //cin>>q1>>q2;
        pr res =query(1,1,n,q1,q2);
        //vector<int>vec=res.first();
        printf("%d\n",res.first.size());
        //cout<<res.first.size()<<endl;
    }
    }
    //init(1,1,n);
    //int r1,r2;
    //cin>>r1>>r2;
    //cout<<query(1,1,n,r1,r2);
}*/
/*
#include<bits/stdc++.h>
using namespace std;
#define mx 100001
int ara[mx];
set<int> tree[mx*3];
void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].insert(ara[b]);
        return;
    }
    int left = node*2;
    int right = node*2 +1;
    int mid =(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    set_union(tree[left].begin(), tree[left].end(),
				tree[right].begin(), tree[right].end(),
				inserter(tree[node], tree[node].begin()));
}
set<int> query(int node,int b,int e,int i,int j)
{
    set<int>st;
    if(i>e ||j<b)
        return st;
    if(b>=i&&e<=j)
        return tree[node];
    int left = 2*node;
    int right = 2*node +1;
    int mid = (b+e)/2;
    set<int> q1 = query(left,b,mid,i,j);
    set<int> q2 = query(right,mid+1,e,i,j);
    if(q1.size()!=0 && q2.size()!=0)
    {
         set_union(q1.begin(), q1.end(),
                    q2.begin(), q2.end(),
                    inserter(st,st.begin()));
         return st;
    }
    else if(q1.size()==0)
        return q2;
    else
        return q1;
}
int main()
{
	int test,cs;
    scanf("%d",&test);
    for(cs=1;cs<=test;cs++)
    {
        int n,q;
        scanf("%d%d",&n,&q);
        int i;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&ara[i]);
        }
        init(1,1,n);
        printf("Case %d:\n",cs);
        for(i=0;i<q;i++)
        {
            int q1,q2;
            scanf("%d%d",&q1,&q2);
            set<int> res =query(1,1,n,q1,q2);
            printf("%d\n",res.size());
        }
    }
}
*/
