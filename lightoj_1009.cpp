#include<bits/stdc++.h>
using namespace std;
#define mx 20001
vector<int>connected_node[20001];
#define black 5
#define white 0
#define red 1
int vampire,lycan;
int color[20001];
int BFS(int source)
{
    queue<int>bfs_queue;
    color[source]=black;
    vampire++;
    bfs_queue.push(source);
    while(!bfs_queue.empty())
    {
        int u=bfs_queue.front();
        bfs_queue.pop();
        for(int i=0;i<connected_node[u].size();i++)
        {
            int v= connected_node[u][i];
            if(color[v]==white)
            {
                bfs_queue.push(v);
                if(color[u]==black)
                {
                    color[v]=red;
                    lycan++;
                }
                else if(color[u]==red)
                {
                    color[v]=black;
                    vampire++;
                }
            }
        }
    }
}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int test,cs;
    scanf("%d",&test);
    for(cs=1;cs<=test;cs++)
    {
        for(int i=1;i<=mx;i++)
            connected_node[i].clear();
        memset(color,white,sizeof color);
        int n,u,v;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            connected_node[u].push_back(v);
            connected_node[v].push_back(u);
        }
        int ans=0;
        //cout<<"Debug1"<<endl;
        for(int i=1;i<mx;i++)
        {
            if(color[i]==white && connected_node[i].size()>0)
            {
                vampire=0;
                lycan=0;
                BFS(i);
                ans+=max(vampire,lycan);
            }
        }
        printf("Case %d: %d\n",cs,ans);
    }
}
