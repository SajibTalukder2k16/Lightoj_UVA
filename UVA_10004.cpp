#include<bits/stdc++.h>
using namespace std;
vector<int>adj[201];
#define white 0
#define black 1
#define red 5
int color[201];
bool BFS(int source)
{
    //cout<<"Source: "<<source<<endl;
    queue<int>bfs_queue;
    bfs_queue.push(source);
    color[source]=black;
    int u,v;
    while(!bfs_queue.empty())
    {
        u = bfs_queue.front();
        bfs_queue.pop();
        //cout<<"front node: "<<u<<endl;
        //cout<<"adjnodesize: "<<adj[u].size()<<endl;
        for(int i=0;i<adj[u].size();i++)
        {
            v=adj[u][i];
            //cout<<"adj. node: "<<v<<endl;
            //cout<<"color: "<<color[u]<<" "<<color[v]<<endl;

            if(color[v]==white)
            {
                bfs_queue.push(v);
                if(color[u]==black)
                {
                    color[v] = red;
                }
                else if(color[u]==red)
                {
                    color[v] = black;
                }
            }
            else if(color[v]==color[u])
            {
                return false;
            }

        }

    }
    return true;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int nodes;
    while(cin>>nodes)
    {
        if(nodes==0)
            break;
        for(int i=0;i<201;i++)
            adj[i].clear();
        int edges;
        cin>>edges;
        int u,v;
        //cout<<"No of edges: "<<edges<<endl;
        for(int i=0;i<edges;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        memset(color,white,sizeof color);
        int source = u;///as strongly connected graph
        int ans = BFS(source);
        if(ans==0)
        {
            cout<<"NOT BICOLORABLE."<<endl;
        }
        else if(ans==1)
        {
            cout<<"BICOLORABLE."<<endl;
        }
    }


}
