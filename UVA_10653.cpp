#include<bits/stdc++.h>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define pb push_back
#define mp make_pair
#define white 0
#define grey 1
#define black 2
///UVA 10653
int row,col;
#define sz 1001
bool visited[sz][sz]={false};
bool maze[sz][sz]={false};
int level[sz][sz]={0};
int fx[]={+1,-1,0,0};
int fy[]={0,0,+1,-1};
int start_x,start_y,dest_x,dest_y;
bool check(int x,int y)
{
    if(x>0 && x<=row && y>0 && y<=col)
        if(visited[x][y]==false && maze[x][y]==false)
            return true;
        else
            return false;
    else
        return false;
}
void bfs_in_2d_grid(int x,int y)
{
    visited[x][y]=true;
    queue<pair<int,int> >bfs_queue;
    bfs_queue.push(mp(x,y));
    level[x][y]=0;
    while(!bfs_queue.empty())
    {
        int xx,xy;
        xx=bfs_queue.front().first;
        xy=bfs_queue.front().second;
        bfs_queue.pop();
        for(int i=0;i<4;i++)
        {
            int vx=xx+fx[i];
            int vy=xy+fy[i];
            //cout<<"check: "<<check(vx,vy)<<endl;
            if(check(vx,vy))
            {
                visited[vx][vy]=true;
                level[vx][vy]=level[xx][xy]+1;
                //cout<<xx<<" "<<xy<<" "<<vx<<" "<<vy<<" "<<level[xx][xy]<<" "<<level[vx][vy]<<endl;
                bfs_queue.push(mp(vx,vy));
            }
        }
    }
}
int main()
{
    //fileRead
    //fileWrite
    while(true)
    {
        cin>>row>>col;
        if(row==0 && col==0)
            break;
        int no;
        cin>>no;
        int cur_row,cur_col;
        int no_of_obstacle;
        while(no--)
        {
            cin>>cur_row;
            cur_row++;
            cin>>no_of_obstacle;
            while(no_of_obstacle--)
            {
                cin>>cur_col;
                cur_col++;
                maze[cur_row][cur_col]=true;
            }
        }
        cin>>start_x>>start_y;
        cin>>dest_x>>dest_y;
        start_x++,start_y++,dest_x++,dest_y++;
        bfs_in_2d_grid(start_x,start_y);;
        cout<<level[dest_x][dest_y]<<endl;
        memset(maze,0,sizeof maze);
        memset(visited,0,sizeof visited);
        memset(level,0,sizeof level);
    }
}
