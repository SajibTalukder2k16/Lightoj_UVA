#include<bits/stdc++.h>
using namespace std;
#define sz 26
struct node{
    bool endmark;
    node *children[sz+1];
    node(){
        endmark = false;
        for(int i=0;i<sz;i++)
        {
            children[i]=NULL;
        }
    }

}*root;
void insert_node(string str){
    node* cur = root;
    int len = str.size();
    //cout<<len<<endl;
    for(int i=0;i<len;i++)
    {
        int id =str[i]-'a';
        if(cur->children[id]==NULL)
            cur->children[id]=new node();
        cur = cur->children[id];
    }
    cur->endmark = true;
}
bool search_word(string str){
    node* cur = root;
    int len = str.size();
    for(int i=0;i<len;i++)
    {
        int id = str[i]-'a';
        if(cur->children[id]==NULL)
            return false;
        cur = cur->children[id];
    }
    return cur->endmark;
}
void del_node(node* cur)
{
    for(int i=0;i<sz;i++){
        if(cur->children[i])
            del_node(cur->children[i]);
    }
    delete (cur);
}
int main()
{
    root = new node();
    int num_word;
    cout<<"No. of word: ";
    cin>>num_word;
    for(int i =1;i<=num_word;i++)
    {
        string str;
        cin>>str;
        insert_node(str);
    }
    cout<<"No of query: ";
    int query;
    cin >> query;
    for (int i = 1; i <= query; i++) {
        string str;
        cin>>str;
        if (search_word(str))
            puts("FOUND");
        else
            puts("NOT FOUND");
    }
    del_node(root);
}
