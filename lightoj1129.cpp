#include<bits/stdc++.h>
using namespace std;
struct node
{
    node *next[10];
    bool endpoint;
    node()
    {
        endpoint = false;
        for(int i=0;i<10;i++)
        {
            next[i]=NULL;
        }
    }
} *root;
bool insert_word(string str)
{
    node *cur = root;
    int len = str.length();
    for(int i=0;i<len;i++)
    {
        int id = str[i]-'0';
        if(cur->next[id]==NULL)
        {
            cur->next[id] = new node();
        }
        if(cur->endpoint)
            return false;
        cur = cur->next[id];
    }
    if(cur->endpoint==true)
        return false;
    cur->endpoint = true;
    for(int i=0;i<10;i++)
        if(cur->next[i])
            return false;
    return true;
}
void del(node *cur)
{
    for(int i=0;i<10;i++)
    {
        if(cur->next[i])
        {
            del(cur->next[i]);
        }
    }
    delete(cur);
}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
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
        bool chk = true;
        for(int i=0;i<n;i++)
        {
            cin>>str;
            if(chk)
                chk = insert_word(str);
        }
        if(chk)
            printf("Case %d: YES\n",cs);
        else
            printf("Case %d: NO\n",cs);
        del(root);
    }
}
