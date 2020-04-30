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
int fx[]={+1,-1,0,0};
int fy[]={0,0,+1,-1};
///lightoj 1066
#define sz 501
int n;
char max_char = 'A';
bool visited[sz][sz]={false};
int level[sz][sz]={false};
char maze[sz][sz];
bool check_inside_the_maze(int x,int y,char cur_ch)
{
    if(x>0 && x<=n && y>0 && y<=n)
        if(visited[x][y]==false && maze[x][y]!='#'&& maze[x][y]<=cur_ch)
            return true;
        else
            return false;
    else
        return false;
}
int cnt=0;
bool t=false;
void BFS_in_2d_grid(int x,int y,char cur_char)
{
    ///       cout<<cur_char<<endl;
    if(cur_char==max_char+1)
    {
        t=true;
        return;
    }
    memset(visited,0,sizeof visited);
    memset(level,0,sizeof level);
    visited[x][y]=true;
    queue<pair<int,int> >bfs_queue;
    bfs_queue.push(mp(x,y));
    level[x][y]=0;
    while(!bfs_queue.empty())
    {
        int ux=bfs_queue.front().first;
        int uy=bfs_queue.front().second;
        bfs_queue.pop();
        for(int i=0;i<4;i++)
        {
            int vx=ux+fx[i];
            int vy=uy+fy[i];
            if(check_inside_the_maze(vx,vy,cur_char))
            {
                visited[vx][vy]=true;
                level[vx][vy]=level[ux][uy]+1;
                if(maze[vx][vy]==cur_char)
                {
                    cnt+=level[vx][vy];
                    BFS_in_2d_grid(vx,vy,cur_char+1);
                    return;
                }
                bfs_queue.push(mp(vx,vy));
            }
        }

    }

}
int main()
{
//    fileRead
//    fileWrite
    int test;
    cin>>test;
    for(int cs=1;cs<=test;cs++)
    {
        cin>>n;
        int x,y;
        max_char='A';
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>maze[i][j];
                if(maze[i][j]=='A')
                    x=i,y=j;
                if(maze[i][j]>'A' && maze[i][j]<='Z' && max_char<maze[i][j])
                    max_char=maze[i][j];
            }
        }
        BFS_in_2d_grid(x,y,'B');

        if(!t)
        {
            cout<<"Case "<<cs<<": Impossible"<<endl;
        }
        else
        {
            cout<<"Case "<<cs<<": "<<cnt<<endl;
        }
        //cnt_alphabet=1;
        cnt=0;
        t=false;

    }
}
