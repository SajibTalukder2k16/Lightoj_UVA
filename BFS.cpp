vector<int>adj[31];
bool visited[31];
int level[31]={0};
int BFS(int source)
{
   visited[source]=true;
   queue<int>bfs_queue;
   bfs_queue.push(source);
   level[source]=0;
   while(!bfs_queue.empty())
   {
       int u = bfs_queue.front();
       bfs_queue.pop();

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
