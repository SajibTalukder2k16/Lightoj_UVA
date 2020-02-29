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
    //cout<<"inside: "<<endl;
    node *cur = root;
    int len = str.length();
    for(int i=0;i<len;i++)
    {
        int id = str[i]-'0';
        if(cur->next[id]==NULL)
        {
            cur->next[id] = new node();
        }
        if(cur->endpoint==true)
            return false;
        cur = cur->next[id];
    }
    if(cur->endpoint==true)
        return false;
    cur->endpoint = true;
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
