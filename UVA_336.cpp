#include<bits/stdc++.h>
using namespace std;
vector<int>adj[31];
bool visited[31];
int level[31]={0};
int BFS(int source,int ttl)
{
   visited[source]=true;
   queue<int>bfs_queue;
   bfs_queue.push(source);
   level[source]=0;
   while(!bfs_queue.empty())
   {
       int u = bfs_queue.front();
       bfs_queue.pop();
       if(level[u]<ttl)
       {
           for(int i=0;i<adj[u].size();i++)
           {
               int v = adj[u][i];
               if(visited[v]==false)
               {
                   visited[v]=true;
                   level[v]=level[u]+1;
                   bfs_queue.push(v);
               }
           }
       }

   }
   int cnt =  0;
   for(int i=1;i<=30;i++)
    if(visited[i]==true)
        cnt++;

    //cout<<cnt<<endl;
   return cnt;
}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int n;
    int cs=1;
    while(cin>>n)
    {
        if(n==0)
            break;
        for(int i=1;i<31;i++)
            adj[i].clear();
        map<int,int>mp;
        int node=1,u,v;
        for(int i=0;i<n;i++)
        {
            cin>>u>>v;
            if(mp[u]==0)
                mp[u]=node++;
            if(mp[v]==0)
                mp[v]=node++;
            u=mp[u];
            v=mp[v];
            adj[u].push_back(v);
            adj[v].push_back(u);
            //cout<<u<<" "<<v<<endl;
        }
        node--;
        int source,ttl;
        while(cin>>source>>ttl)
        {
            if(source==0 && ttl==0)
                break;
            memset(visited,false,sizeof visited);
            //Case 1: 5 nodes not reachable from node 35 with TTL = 2.
            cout<<"Case "<<cs++<<": "<<node-BFS(mp[source],ttl)<<" nodes not reachable from node "<<source<<" with TTL = "<<ttl<<"."<<endl;;
        }
    }
}
