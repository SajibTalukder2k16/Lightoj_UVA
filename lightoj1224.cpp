#include<bits/stdc++.h>
using namespace std;
struct node
{
    int count_prefix;
    node *next[4];
    node()
    {
        count_prefix = 0;
        for(int i=0;i<4;i++)
        {
            next[i]=NULL;
        }
    }
} *root;
void insert_word(string str)
{
    node *cur = root;
    int len = str.length();
    for(int i=0;i<len;i++)
    {
        int id;
        if(str[i]=='A')
            id=0;
        else if(str[i]=='C')
            id =1;
        else if(str[i]=='G')
            id = 2;
        else if(str[i]=='T')
            id = 3;
        if(cur->next[id]==NULL)
        {
            cur->next[id] = new node();
        }
        cur->next[id]->count_prefix++;
        cur = cur->next[id];
    }
}
void del(node *cur)
{
    for(int i=0;i<4;i++)
    {
        if(cur->next[i])
        {
            del(cur->next[i]);
        }
    }
    delete(cur);
}
int query(node *cur,int level)
{
    int ret = cur->count_prefix*(level);
    for(int i=0;i<4;i++)
    {
        if(cur->next[i])
        {
            ret = max(ret,query(cur->next[i],level+1));
        }
    }
    return ret;

}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    for(int cs=1;cs<=test;cs++)
    {
        root = new node();
        int n;
        cin>>n;
        string str;
        for(int i=0;i<n;i++)
        {
            cin>>str;
            insert_word(str);
        }
        printf("Case %d: %d\n",cs,query(root,0));
        del(root);
    }
}
